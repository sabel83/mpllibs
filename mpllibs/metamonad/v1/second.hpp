#ifndef MPLLIBS_METAMONAD_V1_SECOND_HPP
#define MPLLIBS_METAMONAD_V1_SECOND_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/second.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // LAZY_METAFUNCTION uses lambda, which uses pairs
      template <class P>
      struct second : P::type::second {};
    }
  }
}

#endif

