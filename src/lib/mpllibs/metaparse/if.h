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
    template <class p, class t, class f>
    struct if_
    {
      template <class s, class pos>
      struct apply :
        boost::mpl::apply<
          mpllibs::metaparse::return_<
            typename boost::mpl::if_<
              mpllibs::metaparse::is_error<boost::mpl::apply<p, s, pos> >,
              f,
              t
            >::type
          >,
          s,
          pos
        >
      {};
    };
  }
}

#endif

