// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/in_range.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::in_range");

  typedef
    boost::mpl::apply<mpllibs::metaparse::util::in_range<int10, int13>, int12>
    TestIntInRange;

  typedef
    boost::mpl::apply<mpllibs::metaparse::util::in_range<int10, int13>, int10>
    TestLowerBound;

  typedef
    boost::mpl::apply<mpllibs::metaparse::util::in_range<int10, int13>, int13>
    TestUpperBound;

  typedef
    boost::mpl::apply<mpllibs::metaparse::util::in_range<int10, int13>, int14>
    TestIntNotInRange;    
}

MPLLIBS_ADD_TEST(suite, TestIntInRange)
MPLLIBS_ADD_TEST(suite, TestLowerBound)
MPLLIBS_ADD_TEST(suite, TestUpperBound)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestIntNotInRange)

