// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_char.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("is_char");

  typedef
    boost::mpl::apply<
      mpllibs::util::is_char<boost::mpl::integral_c<char, 'a'> >,
      boost::mpl::integral_c<char, 'a'>
    >
    TestSame;
  
  typedef
    boost::mpl::apply<
      mpllibs::util::is_char<boost::mpl::integral_c<char, 'a'> >,
      boost::mpl::integral_c<char, 'b'>
    >
    TestDifferent;
}

MPLLIBS_ADD_TEST(suite, TestSame)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestDifferent)

