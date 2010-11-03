#ifndef MPLLIBS_PARSER_EMPTY_H
#define MPLLIBS_PARSER_EMPTY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nothing.h>
#include <mpllibs/metaparse/util/pair.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/empty.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class result>
    struct empty
    {
      template <class s>
      struct apply :
        boost::mpl::if_<
          typename boost::mpl::empty<s>::type,
          mpllibs::metaparse::util::pair<result, s>,
          mpllibs::metaparse::nothing
        >
      {};
    };
  }
}

#endif

