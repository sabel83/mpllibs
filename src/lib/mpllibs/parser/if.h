#ifndef MPLLIBS_PARSER_IF_H
#define MPLLIBS_PARSER_IF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/always.h>
#include <mpllibs/parser/return.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class t, class f>
    struct if_ :
      mpllibs::parser::one_of<
        mpllibs::parser::always<p, t>,
        mpllibs::parser::return_<f>
      >
    {};
  }
}

#endif

