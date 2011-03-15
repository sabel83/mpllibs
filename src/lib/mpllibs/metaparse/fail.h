#ifndef MPLLIBS_PARSER_FAIL_H
#define MPLLIBS_PARSER_FAIL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/error.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <class msg>
    struct fail
    {
      template <class s, class pos>
      struct apply : mpllibs::metaparse::error<msg, pos> {};
    };
  }
}

#endif

