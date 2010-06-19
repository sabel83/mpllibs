#ifndef MPLLIBS_PARSER_ANY1_H
#define MPLLIBS_PARSER_ANY1_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p>
    struct any1 :
      mpllibs::parser::transform<
        mpllibs::parser::sequence<p, mpllibs::parser::any<p> >,
        mpllibs::util::cons
      >
    {};
  }
}

#endif

