// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/in_range.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/int.hpp>

namespace
{
  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<12> >
    InRange_TestIntInRange;

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<10> >
    InRange_TestLowerBound;

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<13> >
    InRange_TestUpperBound;

  typedef
    mpllibs::util::in_range<
      boost::mpl::int_<10>,
      boost::mpl::int_<13>
    >::apply<boost::mpl::int_<14> >
    InRange_TestIntNotInRange;    
}

MPLLIBS_ADD_TEST(InRange_TestIntInRange)
MPLLIBS_ADD_TEST(InRange_TestLowerBound)
MPLLIBS_ADD_TEST(InRange_TestUpperBound)
MPLLIBS_ADD_TEST_TO_FAIL(InRange_TestIntNotInRange)

