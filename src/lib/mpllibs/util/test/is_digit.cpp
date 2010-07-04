// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_digit.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

namespace
{
  const mpllibs::test::TestSuite suite("is_digit");

  typedef
    mpllibs::util::is_digit::apply<boost::mpl::integral_c<char, '7'> >
    TestDigit;
  
  typedef
    mpllibs::util::is_digit::apply<boost::mpl::integral_c<char, 'a'> >
    TestNonDigit;
}

MPLLIBS_ADD_TEST(suite, TestDigit)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonDigit)

