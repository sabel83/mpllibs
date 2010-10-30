#ifndef MPLLIBS_PARSER_SPACES_H
#define MPLLIBS_PARSER_SPACES_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.h>
#include <mpllibs/metaparse/space.h>

namespace mpllibs
{
  namespace metaparse
  {
    typedef mpllibs::metaparse::any<mpllibs::metaparse::space> spaces;
  }
}

#endif

