#ifndef MPLLIBS_METAMONAD_V1_EVAL_LET_C_HPP
#define MPLLIBS_METAMONAD_V1_EVAL_LET_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/eval_let_c.hpp>
#include <mpllibs/metamonad/v1/let_c.hpp>
#include <mpllibs/metamonad/v1/eval_syntax.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(eval_let_c, (N)(E1)(E2))
      ((eval_syntax<let_c<N, E1, E2> >));
    }
  }
}

#endif

