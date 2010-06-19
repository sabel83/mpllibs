// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/in_range.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

#include <boost/mpl/int.hpp>

namespace
{
  struct TestIntInRange :
    mpllibs::test::test<
      mpllibs::util::in_range<
        boost::mpl::int_<10>,
        boost::mpl::int_<13>
      >::apply<boost::mpl::int_<12> >::type
    >
  {};

  struct TestLowerBound :
    mpllibs::test::test<
      mpllibs::util::in_range<
        boost::mpl::int_<10>,
        boost::mpl::int_<13>
      >::apply<boost::mpl::int_<10> >::type
    >
  {};

  struct TestUpperBound :
    mpllibs::test::test<
      mpllibs::util::in_range<
        boost::mpl::int_<10>,
        boost::mpl::int_<13>
      >::apply<boost::mpl::int_<13> >::type
    >
  {};

  struct TestIntNotInRange :
    mpllibs::test::test_fail<
      mpllibs::util::in_range<
        boost::mpl::int_<10>,
        boost::mpl::int_<13>
      >::apply<boost::mpl::int_<14> >::type
    >
  {};
}


