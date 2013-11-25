#ifndef MPLLIBS_METAMONAD_V1_BIND__HPP
#define MPLLIBS_METAMONAD_V1_BIND__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/bind_.hpp>
#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(bind_, (MonadTag)(A)(B))
      ((apply<typename monad<MonadTag>::bind_, A, B>));
    }
  }
}

#endif

