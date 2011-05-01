#ifndef MPLLIBS_PARSER_ANY1_H
#define MPLLIBS_PARSER_ANY1_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.h>

#include <boost/mpl/if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct any1
    {
      template <class S, class Pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            is_error<boost::mpl::apply<P, S, Pos> >,
            P,
            any<P>
          >::type,
          S,
          Pos
        >
      {};
    };
  }
}

#endif

