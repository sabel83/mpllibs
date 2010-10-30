// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/pair.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::pair");
  
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::util::pair<int11, int13>,
      mpllibs::metaparse::util::pair<int11, int13>
    >
    TestEquality;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::util::pair<int11, int13>,
      mpllibs::metaparse::util::pair<int11, int11>
    >
    TestNonEquality;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::util::pair<int11, int13>::type,
      mpllibs::metaparse::util::pair<int11, int13>
    >
    TestNestedType;
}

MPLLIBS_ADD_TEST(suite, TestEquality)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonEquality)
MPLLIBS_ADD_TEST(suite, TestNestedType)

