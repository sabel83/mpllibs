#ifndef MPLLIBS_METAPARSE_V2_KEEP_MIDDLE_HPP
#define MPLLIBS_METAPARSE_V2_KEEP_MIDDLE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/nth_of.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P1, class P2, class P3>
      struct middle_of : nth_of_c<1, P1, P2, P3> {};
    }
  }
}

#endif

