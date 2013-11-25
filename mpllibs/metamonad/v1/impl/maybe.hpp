#ifndef MPLLIBS_METAMONAD_V1_IMPL_MAYBE_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MAYBE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/data.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_DATA(maybe, 1, ((just, 1))((nothing, 0)));
    }
  }
}

#endif

