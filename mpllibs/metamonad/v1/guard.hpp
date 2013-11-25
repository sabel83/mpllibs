#ifndef MPLLIBS_METAMONAD_V1_GUARD_HPP
#define MPLLIBS_METAMONAD_V1_GUARD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/guard.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/mzero.hpp>

#include <boost/mpl/void.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(guard, (MonadTag)(B))
      ((if_<B, return_<MonadTag, boost::mpl::void_>, mzero<MonadTag> >));
    }
  }
}

#endif

