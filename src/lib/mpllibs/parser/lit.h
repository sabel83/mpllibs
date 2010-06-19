#ifndef MPLLIBS_PARSER_LIT_H
#define MPLLIBS_PARSER_LIT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/accept_when.h>
#include <mpllibs/parser/one_char.h>

#include <mpllibs/util/is_char.h>

namespace mpllibs
{
  namespace parser
  {
    template <class c>
    struct lit :
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_char<c>
      >
    {};
  }
}

#endif


