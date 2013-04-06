#ifndef MPLLIBS_METAMONAD_MPLUS_HPP
#define MPLLIBS_METAMONAD_MPLUS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(mplus, (MonadTag)(A)(B))
    ((apply<typename monad_plus<MonadTag>::mplus, A, B>));
  }
}

#endif

