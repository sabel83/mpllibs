#ifndef MPLLIBS_PARSER_EXCEPT_H
#define MPLLIBS_PARSER_EXCEPT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/fail.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class Result, class ErrorMsg>
    struct except
    {
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            is_error<boost::mpl::apply<P, S, Pos> >,
            return_<Result>,
            fail<ErrorMsg>
          >::type,
          S,
          Pos
        >
      {};
    };
  }
}

#endif

