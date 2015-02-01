#ifndef MPLLIBS_METAPARSE_V2_FOLDR_HPP
#define MPLLIBS_METAPARSE_V2_FOLDR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/return_.hpp>
#include <mpllibs/metaparse/v2/foldrp.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class State, class BackwardOp>
      struct foldr : foldrp<P, return_<State>, BackwardOp> {};
    }
  }
}

#endif

