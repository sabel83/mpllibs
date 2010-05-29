#ifndef MPLLIBS_TEST_TEST_EQUAL_SEQUENCE_H
#define MPLLIBS_TEST_TEST_EQUAL_SEQUENCE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/test_c.h>
#include <mpllibs/test/equal_sequence.h>

namespace mpllibs
{
  namespace test
  {
    template <class a, class b>
    struct test_equal_sequence :
      mpllibs::test::test_c<mpllibs::test::equal_sequence<a, b>::type::value>
    {};
  }
}

#endif

