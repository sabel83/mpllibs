#ifndef MPLLIBS_METAMONAD_MZERO_HPP
#define MPLLIBS_METAMONAD_MZERO_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(mzero, (MonadTag))
    ((typename monad_plus<MonadTag>::mzero));
  }
}

#endif

