// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_digit.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("is_digit");

  typedef
    boost::mpl::apply<
      mpllibs::util::is_digit,
      boost::mpl::integral_c<char, '7'>
    >
    TestDigit;
  
  typedef
    boost::mpl::apply<
      mpllibs::util::is_digit,
      boost::mpl::integral_c<char, 'a'>
    >
    TestNonDigit;
}

MPLLIBS_ADD_TEST(suite, TestDigit)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonDigit)

