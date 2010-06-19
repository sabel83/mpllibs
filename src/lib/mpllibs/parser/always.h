#ifndef MPLLIBS_PARSER_ALWAYS_H
#define MPLLIBS_PARSER_ALWAYS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/return.h>
#include <mpllibs/parser/second_of.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class result>
    struct always :
      mpllibs::parser::second_of<p, mpllibs::parser::return_<result> >
    {};
  }
}

#endif

