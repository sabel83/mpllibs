#ifndef MPLLIBS_METAMONAD_MAPPEND_HPP
#define MPLLIBS_METAMONAD_MAPPEND_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class Tag>
    struct monoid;

    MPLLIBS_METAFUNCTION(mappend, (MonadTag)(A)(B))
    ((boost::mpl::apply_wrap2<typename monoid<MonadTag>::mappend, A, B>));
  }
}

#endif

