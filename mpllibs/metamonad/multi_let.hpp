#ifndef MPLLIBS_METAMONAD_MULTI_LET_HPP
#define MPLLIBS_METAMONAD_MULTI_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/pair.hpp>
#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      MPLLIBS_METAFUNCTION_CLASS(multi_let_op, (S)(P))
      ((
        let<
          typename boost::mpl::first<P>::type,
          typename boost::mpl::second<P>::type,
          S
        >
      ));
    }

    MPLLIBS_METAFUNCTION(multi_let, (M)(E))
    ((boost::mpl::fold<M, E, impl::multi_let_op>));
  }
}

#endif

