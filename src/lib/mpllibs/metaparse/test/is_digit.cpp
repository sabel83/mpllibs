// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_digit.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::util::is_digit;

using boost::mpl::apply;

namespace
{
  const test_suite suite("util::is_digit");

  typedef apply<is_digit, char_7> test_digit;
  
  typedef apply<is_digit, char_a> test_non_digit;
}

MPLLIBS_ADD_TEST(suite, test_digit)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_non_digit)

