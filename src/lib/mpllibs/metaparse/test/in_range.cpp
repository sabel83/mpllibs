// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/in_range.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::util::in_range;

using boost::mpl::apply;

namespace
{
  const test_suite suite("util::in_range");

  typedef apply<in_range<int10, int13>, int12> test_int_in_range;

  typedef apply<in_range<int10, int13>, int10> test_lower_bound;

  typedef apply<in_range<int10, int13>, int13> test_upper_bound;

  typedef apply<in_range<int10, int13>, int14> test_int_not_in_range;    
}

MPLLIBS_ADD_TEST(suite, test_int_in_range)
MPLLIBS_ADD_TEST(suite, test_lower_bound)
MPLLIBS_ADD_TEST(suite, test_upper_bound)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_int_not_in_range)

