// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/in_range.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/int.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("in_range");

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<12> >
    TestIntInRange;

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<10> >
    TestLowerBound;

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<13> >
    TestUpperBound;

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<14> >
    TestIntNotInRange;    
}

MPLLIBS_ADD_TEST(suite, TestIntInRange)
MPLLIBS_ADD_TEST(suite, TestLowerBound)
MPLLIBS_ADD_TEST(suite, TestUpperBound)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestIntNotInRange)

