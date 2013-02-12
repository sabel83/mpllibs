#ifndef MPLLIBS_METAMONAD_EXAMPLE_PRINT_EMPTY_HPP
#define MPLLIBS_METAMONAD_EXAMPLE_PRINT_EMPTY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

struct print_empty : mpllibs::metamonad::tmp_value<print_empty>
{
  static bool run()
  {
    // The next element is the first one
    return true;
  }
};

#endif

