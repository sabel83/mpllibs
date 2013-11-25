#ifndef MPLLIBS_METAMONAD_V1_MULTI_LET_HPP
#define MPLLIBS_METAMONAD_V1_MULTI_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/multi_let.hpp>
#include <mpllibs/metamonad/v1/let.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>

#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(multi_let, (M)(E))
      ((boost::mpl::fold<M, E, lambda_c<s, p, let<first<p>, second<p>, s> > >));
    }
  }
}

#endif

