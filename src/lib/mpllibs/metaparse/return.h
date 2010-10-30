#ifndef MPLLIBS_PARSER_RETURN_H
#define MPLLIBS_PARSER_RETURN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/pair.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <class c>
    struct return_
    {
      template <class S>
      struct apply : mpllibs::metaparse::util::pair<c, S> {};
    };
  }
}

#endif

