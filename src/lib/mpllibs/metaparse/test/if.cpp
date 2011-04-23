// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/if.h>
#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::if_;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::start;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const TestSuite suite("if");

  typedef
    equal_to<
      get_result<apply<if_<digit, int11, int13>, str_1, start> >::type,
      int11
    >
    test_true;
    
  typedef
    equal_to<
      get_result<apply<if_<digit, int11, int13>, str_a, start> >::type,
      int13
    >
    test_false;
}

MPLLIBS_ADD_TEST(suite, test_true)
MPLLIBS_ADD_TEST(suite, test_false)

