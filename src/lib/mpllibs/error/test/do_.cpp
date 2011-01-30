// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/do_.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("do_");

  typedef
    boost::mpl::equal_to<
      Right<int11>,
      DO<
        SET<x, boost::mpl::apply<RETURN<Either>, int13> >,
        boost::mpl::apply<minus_2, x>
      >::type
    >
    TestDo;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      DO<
        SET<x, boost::mpl::apply<RETURN<Either>, int13> >,
        SET<y, boost::mpl::apply<minus_2, x> >,
        boost::mpl::apply<minus_2, y>
      >::type
    >
    TestDoThreeSteps;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      DO<
        SET<x, boost::mpl::apply<RETURN<Either>, int13> >,
        SET<y, boost::mpl::apply<minus_2, x> >,
        boost::mpl::apply<minus_2, x>,
        boost::mpl::apply<minus_2, y>
      >::type
    >
    TestDoTwoCalls;

  typedef
    boost::mpl::equal_to<
      Right<int13>,
      DO<
        boost::mpl::apply<RETURN<Either>, int11>,
        boost::mpl::apply<RETURN<Either>, int13>
      >::type
    >
    TestDoTwoReturns;
}

MPLLIBS_ADD_TEST(suite, TestDo)
MPLLIBS_ADD_TEST(suite, TestDoThreeSteps)
MPLLIBS_ADD_TEST(suite, TestDoTwoCalls)
MPLLIBS_ADD_TEST(suite, TestDoTwoReturns)


