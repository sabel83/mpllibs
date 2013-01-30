#ifndef MPLLIBS_METAMONAD_EVAL_LETREC_HPP
#define MPLLIBS_METAMONAD_EVAL_LETREC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/letrec.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(eval_letrec, (N)(E1)(E2))
    ((eval_syntax<letrec<N, E1, E2> >));
  }
}

#endif

