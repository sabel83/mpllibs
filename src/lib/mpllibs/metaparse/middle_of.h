#ifndef MPLLIBS_PARSER_KEEP_MIDDLE_H
#define MPLLIBS_PARSER_KEEP_MIDDLE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p1, class p2, class p3>
    struct middle_of : mpllibs::metaparse::nth_of_c<1, p1, p2, p3> {};
  }
}

#endif

