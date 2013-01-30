#ifndef MPLLIBS_METAMONAD_EVAL_MULTI_LET_HPP
#define MPLLIBS_METAMONAD_EVAL_MULTI_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/multi_let.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(eval_multi_let, (M)(E))
    ((eval_syntax<multi_let<M, E> >));
  }
}

#endif

