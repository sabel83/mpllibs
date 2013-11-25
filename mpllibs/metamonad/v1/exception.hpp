#ifndef MPLLIBS_METAMONAD_V1_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_V1_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/exception.hpp>
#include <mpllibs/metamonad/v1/algebraic_data_type_tag.hpp>
#include <mpllibs/metamonad/v1/exception_tag.hpp>

#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/eval_case.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

#include <string>
#include <sstream>
#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class Reason>
      struct exception
      {
        typedef exception<typename Reason::type> type;
        typedef algebraic_data_type_tag tag;
  
        static std::string get_value()
        {
          std::ostringstream s;
          s << "exception<" << Reason::get_value() << ">";
          return s.str();
        }
  
        static const std::string value;
      };
  
      template <class Reason>
      const std::string
        exception<Reason>::value = exception<Reason>::get_value();
  
      // Currying
      template <>
      struct exception<boost::mpl::void_> :
        tmp_value<exception<boost::mpl::void_>, tag_tag>
      {
        template <class Reason>
        struct apply : exception<Reason> {};
      };

      /*
       * The Exception monad
       * This is modeled along the Either monad of Haskell
       *
       * A monadic value is either:
       *  - An exception
       *  - Any other value
       *
       */
      
      template <>
      struct monad<exception_tag> : monad_defaults<exception_tag>
      {
        typedef lambda_c<t, t> return_;
        
        typedef
          lambda_c<a, f,
            eval_case< a,
              matches_c<exception<_>, a>,
              matches_c<_, apply<f, a> >
            >
          >
          bind;
      };
    }
  }
}

#endif

