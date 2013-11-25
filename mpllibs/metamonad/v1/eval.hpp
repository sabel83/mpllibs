#ifndef MPLLIBS_METAMONAD_V1_EVAL_HPP
#define MPLLIBS_METAMONAD_V1_EVAL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/eval.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(eval, (E)) ((typename E::type));
    }
  }
}

#endif

