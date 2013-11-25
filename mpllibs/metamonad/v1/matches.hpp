#ifndef MPLLIBS_METAMONAD_V1_MATCHES_HPP
#define MPLLIBS_METAMONAD_V1_MATCHES_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/matches.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class P, class E>
      struct matches : tmp_value<matches<P, E> > {};
    }
  }
}

#endif

