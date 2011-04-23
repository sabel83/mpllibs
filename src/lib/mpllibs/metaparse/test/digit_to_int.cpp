// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/digit_to_int.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::util::digit_to_int;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const test_suite suite("util::digit_to_int");

  typedef equal_to<apply<digit_to_int, char_0>::type, int0> test0;

  typedef equal_to<apply<digit_to_int, char_9>::type, int9> test9;
}

MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test9)


