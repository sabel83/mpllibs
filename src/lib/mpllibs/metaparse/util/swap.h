#ifndef MPLLIBS_UTIL_SWAP_H
#define MPLLIBS_UTIL_SWAP_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/pair.h>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct swap
      {
        template <class p>
        struct apply
        {
          typedef
            mpllibs::metaparse::util::pair<
              typename p::second,
              typename p::first
            >
            type;
        };
      };
    }
  }
}

#endif

