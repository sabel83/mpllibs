#ifndef MPLLIBS_METAMONAD_V1_EVAL_LETREC_C_HPP
#define MPLLIBS_METAMONAD_V1_EVAL_LETREC_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/eval_letrec_c.hpp>
#include <mpllibs/metamonad/v1/letrec_c.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/eval_syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(eval_letrec_c, (N)(E1)(E2))
      ((eval_syntax<letrec_c<N, E1, E2> >));
    }
  }
}

#endif

