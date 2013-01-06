#ifndef MPLLIBS_METAMONAD_UNUSED_ARG_HPP
#define MPLLIBS_METAMONAD_UNUSED_ARG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct _ : tmp_value<_> {};
  }
}

#endif

