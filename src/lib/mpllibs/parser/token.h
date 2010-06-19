#ifndef MPLLIBS_PARSER_TOKEN_H
#define MPLLIBS_PARSER_TOKEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/spaces.h>
#include <mpllibs/parser/first_of.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p>
    struct token : mpllibs::parser::first_of<p, mpllibs::parser::spaces> {};
  }
}

#endif

