// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/swap.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("swap");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::util::swap,
        mpllibs::util::pair<int1, int2>
      >::type,
      mpllibs::util::pair<int2, int1>
    >
    TestSwap;
}

MPLLIBS_ADD_TEST(suite, TestSwap)

