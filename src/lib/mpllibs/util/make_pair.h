#ifndef MPLLIBS_UTIL_MAKE_PAIR_H
#define MPLLIBS_UTIL_MAKE_PAIR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/pair.h>

namespace mpllibs
{
  namespace util
  {
    // Accepts nullary metafunctions
    template <class a, class b>
    struct make_pair
    {
      typedef mpllibs::util::pair<typename a::type, typename b::type> type;
    };
  }
}

#endif

