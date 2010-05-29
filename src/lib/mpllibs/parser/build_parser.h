#ifndef MPLLIBS_PARSER_BUILD_PARSER_H
#define MPLLIBS_PARSER_BUILD_PARSER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/get_first.h>
#include <mpllibs/util/compose.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p>
    struct build_parser : mpllibs::util::compose<mpllibs::util::get_first, p> {};
  }
}

#endif

