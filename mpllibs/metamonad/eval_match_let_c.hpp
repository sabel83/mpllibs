#ifndef MPLLIBS_METAMONAD_EVAL_MATCH_LET_C_HPP
#define MPLLIBS_METAMONAD_EVAL_MATCH_LET_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_match_let.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(eval_match_let_c, (P)(E1)(E2))
    ((eval_match_let<syntax<P>, E1, syntax<E2> >));
  }
}

#endif

