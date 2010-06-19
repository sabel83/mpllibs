#ifndef MPLLIBS_PARSER_KEEP_MIDDLE_H
#define MPLLIBS_PARSER_KEEP_MIDDLE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_first.h>
#include <mpllibs/parser/keep_second.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p1, class p2, class p3>
    struct keep_middle :
      mpllibs::parser::keep_second<p1, mpllibs::parser::keep_first<p2, p3> >
    {};
  }
}

#endif

