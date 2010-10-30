#ifndef MPLLIBS_PARSER_SPACE_H
#define MPLLIBS_PARSER_SPACE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.h>
#include <mpllibs/metaparse/one_char.h>

#include <mpllibs/metaparse/util/is_whitespace.h>

namespace mpllibs
{
  namespace metaparse
  {
    typedef
      mpllibs::metaparse::accept_when<
        mpllibs::metaparse::one_char,
        mpllibs::metaparse::util::is_whitespace
      >
      space;
  }
}

#endif

