// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/swap.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::swap");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::util::swap,
        mpllibs::metaparse::util::pair<int1, int2>
      >::type,
      mpllibs::metaparse::util::pair<int2, int1>
    >
    TestSwap;
}

MPLLIBS_ADD_TEST(suite, TestSwap)

