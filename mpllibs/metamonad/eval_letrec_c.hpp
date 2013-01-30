#ifndef MPLLIBS_METAMONAD_EVAL_LETREC_C_HPP
#define MPLLIBS_METAMONAD_EVAL_LETREC_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/letrec_c.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct letrec_c;

    MPLLIBS_METAFUNCTION(eval_letrec_c, (N)(E1)(E2))
    ((eval_syntax<letrec_c<N, E1, E2> >));
  }
}

#endif

