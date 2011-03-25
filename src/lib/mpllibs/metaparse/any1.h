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
    template <class p>
    struct any1
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::apply<
          typename boost::mpl::if_<
            mpllibs::metaparse::is_error<boost::mpl::apply<p, s, pos> >,
            p,
            mpllibs::metaparse::any<p>
          >::type,
          s,
          pos
        >
      {};
    };
  }
}

#endif

