#ifndef MPLLIBS_METAPARSE_V1_TRANSFORM_HPP
#define MPLLIBS_METAPARSE_V1_TRANSFORM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/accept.hpp>
#include <mpllibs/metaparse/v1/get_result.hpp>
#include <mpllibs/metaparse/v1/get_remaining.hpp>
#include <mpllibs/metaparse/v1/get_position.hpp>
#include <mpllibs/metaparse/v1/unless_error.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class P, class T>
      struct transform
      {
      private:
        template <class R>
        struct apply_transformation_function :
          boost::mpl::apply<T, typename R::type>
        {};
        
      public:
        typedef transform type;
        
        template <class S, class Pos>
        struct apply :
          unless_error<
            boost::mpl::apply<P, S, Pos>,
            accept<
              apply_transformation_function<
                get_result<boost::mpl::apply<P, S, Pos> >
              >,
              get_remaining<boost::mpl::apply<P, S, Pos> >,
              get_position<boost::mpl::apply<P, S, Pos> >
            >
          >
        {};
      };
    }
  }
}

#endif

