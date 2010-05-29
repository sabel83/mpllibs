#ifndef MPLLIBS_TEST_TEST_H
#define MPLLIBS_TEST_TEST_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/test_c.h>

namespace mpllibs
{
  namespace test
  {
    template <class cond>
    struct test : mpllibs::test::test_c<cond::value> {};
  }
}

#endif

