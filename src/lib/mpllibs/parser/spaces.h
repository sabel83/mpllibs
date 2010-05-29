#ifndef MPLLIBS_PARSER_SPACES_H
#define MPLLIBS_PARSER_SPACES_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any.h>
#include <mpllibs/parser/space.h>

namespace mpllibs
{
  namespace parser
  {
    typedef mpllibs::parser::any<mpllibs::parser::space> spaces;
  }
}

#endif

