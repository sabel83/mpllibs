#ifndef MPLLIBS_METAMONAD_FAIL_HPP
#define MPLLIBS_METAMONAD_FAIL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(fail, (MonadTag)(S))
    ((apply<typename mpllibs::metamonad::monad<MonadTag>::fail, S>));
  }
}

#endif

