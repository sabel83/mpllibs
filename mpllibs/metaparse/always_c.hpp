#ifndef MPLLIBS_METAPARSE_ALWAYS_C_HPP
#define MPLLIBS_METAPARSE_ALWAYS_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/lit_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <char C, class Result>
    struct always_c : always<lit_c<C>, Result> {};
  }
}

#endif

