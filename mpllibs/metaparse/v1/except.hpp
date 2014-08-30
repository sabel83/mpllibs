#ifndef MPLLIBS_METAPARSE_V1_EXCEPT_HPP
#define MPLLIBS_METAPARSE_V1_EXCEPT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/is_error.hpp>
#include <mpllibs/metaparse/v1/accept.hpp>
#include <mpllibs/metaparse/v1/reject.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class P, class Result, class ErrorMsg>
      struct except
      {
        typedef except type;
        
        template <class S, class Pos>
        struct apply :
          boost::mpl::if_<
            is_error<boost::mpl::apply<P, S, Pos> >,
            accept<Result, S, Pos>,
            reject<ErrorMsg, Pos>
          >
        {};
      };
    }
  }
}

#endif

