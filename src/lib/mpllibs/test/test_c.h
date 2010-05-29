#ifndef MPLLIBS_TEST_TEST_C_H
#define MPLLIBS_TEST_TEST_C_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/static_assert.hpp>

namespace mpllibs
{
  namespace test
  {
    template <bool cond>
    struct test_c
    {
      BOOST_STATIC_ASSERT(cond);
    };
  }
}

#endif

