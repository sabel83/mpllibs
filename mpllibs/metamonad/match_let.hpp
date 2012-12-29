#ifndef MPLLIBS_METAMONAD_MATCH_LET_HPP
#define MPLLIBS_METAMONAD_MATCH_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/multi_let.hpp>
#include <mpllibs/metamonad/match.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(match_let, (P)(E1)(E2))
    ((multi_let<typename match<P, typename E1::type>::type, E2>));
  }
}

#endif

