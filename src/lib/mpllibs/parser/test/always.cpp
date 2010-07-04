// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/always.h>
#include <mpllibs/parser/nothing.h>
#include <mpllibs/parser/digit.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

namespace
{
  const mpllibs::test::TestSuite suite("always");

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::always<
        mpllibs::parser::digit,
        int13
      >::apply<str_1>::type::first,
      int13
    >
    TestResult;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::always<
        mpllibs::parser::digit,
        int13
      >::apply<str_a>::type,
      mpllibs::parser::nothing
    >
    TestFail;
}

MPLLIBS_ADD_TEST(suite, TestResult)
MPLLIBS_ADD_TEST(suite, TestFail)

