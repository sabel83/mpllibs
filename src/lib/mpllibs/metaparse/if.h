#ifndef MPLLIBS_PARSER_IF_H
#define MPLLIBS_PARSER_IF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/always.h>
#include <mpllibs/metaparse/return.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class t, class f>
    struct if_ :
      mpllibs::metaparse::one_of<
        mpllibs::metaparse::always<p, t>,
        mpllibs::metaparse::return_<f>
      >
    {};
  }
}

#endif

