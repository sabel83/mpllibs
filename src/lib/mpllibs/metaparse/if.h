#ifndef MPLLIBS_PARSER_IF_H
#define MPLLIBS_PARSER_IF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/is_error.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class T, class F>
    struct if_
    {
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply<
          return_<
            typename boost::mpl::if_<
              is_error<boost::mpl::apply<P, S, Pos> >,
              F,
              T
            >::type
          >,
          S,
          Pos
        >
      {};
    };
  }
}

#endif

