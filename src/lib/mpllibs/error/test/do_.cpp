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
      mpllibs::error::do_<
        mpllibs::error::set<
          x,
          mpllibs::error::call<mpllibs::error::return_<Either>, int13>
        >,
        mpllibs::error::call<minus_2, x>
      >::type
    >
    TestDo;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      mpllibs::error::do_<
        mpllibs::error::set<
          x,
          mpllibs::error::call<mpllibs::error::return_<Either>, int13>
        >,
        mpllibs::error::set<y, mpllibs::error::call<minus_2, x> >,
        mpllibs::error::call<minus_2, y>
      >::type
    >
    TestDoThreeSteps;
}

MPLLIBS_ADD_TEST(suite, TestDo)
MPLLIBS_ADD_TEST(suite, TestDoThreeSteps)


