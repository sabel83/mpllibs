#ifndef MPLLIBS_METAPARSE_V2_FOLDRF_HPP
#define MPLLIBS_METAPARSE_V2_FOLDRF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/return_.hpp>
#include <mpllibs/metaparse/v2/foldrp.hpp>
#include <mpllibs/metaparse/v2/first_of.hpp>
#include <mpllibs/metaparse/v2/fail_at_first_char_expected.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class P, class State, class BackwardOp>
      struct foldrf :
        foldrp<
          P,
          first_of<return_<State>, fail_at_first_char_expected<P> >,
          BackwardOp
        >
      {};
    }
  }
}

#endif

