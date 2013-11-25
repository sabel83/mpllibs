#ifndef MPLLIBS_METAMONAD_V1_MATCH_HPP
#define MPLLIBS_METAMONAD_V1_MATCH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/match.hpp>
#include <mpllibs/metamonad/v1/match_c.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class Pattern, class Value>
      struct match<syntax<Pattern>, Value> : match_c<Pattern, Value> {};
    }
  }
}

#endif

