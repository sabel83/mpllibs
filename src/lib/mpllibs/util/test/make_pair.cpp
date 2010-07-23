// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/make_pair.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <mpllibs/util/pair.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("make_pair");
  
  typedef
    boost::mpl::equal_to<
      mpllibs::util::pair<int11, int13>,
      mpllibs::util::make_pair<int11, int13>::type
    >
    TestPairCreation;
}

MPLLIBS_ADD_TEST(suite, TestPairCreation)

