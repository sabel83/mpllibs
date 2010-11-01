#ifndef MPLLIBS_PARSER_ALWAYS_H
#define MPLLIBS_PARSER_ALWAYS_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/last_of.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <class p, class result>
    struct always :
      mpllibs::metaparse::last_of<p, mpllibs::metaparse::return_<result> >
    {};
  }
}

#endif

