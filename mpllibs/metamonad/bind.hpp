#ifndef MPLLIBS_METAMONAD_BIND_HPP
#define MPLLIBS_METAMONAD_BIND_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class MonadTag>
    struct monad;

    MPLLIBS_METAFUNCTION(bind, (MonadTag)(A)(F))
    ((apply<typename monad<MonadTag>::bind, A, F>));
  }
}

#endif

