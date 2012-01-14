#ifndef MPLLIBS_METAPARSE_FOLDR_HPP
#define MPLLIBS_METAPARSE_FOLDR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/foldrp.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P, class State, class BackwardOp>
    struct foldr : foldrp<P, return_<State>, BackwardOp> {};
  }
}

#endif

