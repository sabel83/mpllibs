#ifndef MPLLIBS_METAMONAD_MCONCAT_HPP
#define MPLLIBS_METAMONAD_MCONCAT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(mconcat, (MonadTag)(L))
    ((boost::mpl::apply_wrap1<typename monoid<MonadTag>::mconcat, L>));
  }
}

#endif

