#ifndef MPLLIBS_METAMONAD_MULTI_LET_HPP
#define MPLLIBS_METAMONAD_MULTI_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/first.hpp>
#include <mpllibs/metamonad/second.hpp>

#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(multi_let, (M)(E))
    ((boost::mpl::fold<M, E, lambda_c<s, p, let<first<p>, second<p>, s> > >));
  }
}

#endif

