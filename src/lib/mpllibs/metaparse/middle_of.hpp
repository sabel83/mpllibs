#ifndef MPLLIBS_METAPARSE_KEEP_MIDDLE_HPP
#define MPLLIBS_METAPARSE_KEEP_MIDDLE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P1, class P2, class P3>
    struct middle_of : nth_of_c<1, P1, P2, P3> {};
  }
}

#endif

