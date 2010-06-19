#ifndef MPLLIBS_PARSER_ALPHANUM_H
#define MPLLIBS_PARSER_ALPHANUM_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/letter.h>

namespace mpllibs
{
  namespace parser
  {
    typedef
      mpllibs::parser::one_of<mpllibs::parser::letter, mpllibs::parser::digit>
      alphanum;
  }
}

#endif

