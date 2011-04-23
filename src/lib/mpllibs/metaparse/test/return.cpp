// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::return_;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::get_remaining;
using mpllibs::metaparse::get_position;
using mpllibs::metaparse::start;

using boost::mpl::apply;
using boost::mpl::equal_to;

namespace
{
  const TestSuite suite("return");

  typedef apply<return_<int1>, int2, int3> acc;
  
  typedef return_<char_x> return_x;

  typedef
    equal_to<get_result<apply<return_x, str_hello, start> >::type, char_x>
    test_for_non_empty_string;

  typedef
    equal_to<get_result<apply<return_x, str_, start> >::type, char_x>
    test_for_empty_string;

 
  typedef equal_to<int1, get_result<acc>::type> test_get_result;

  typedef equal_to<int2, get_remaining<acc>::type> test_get_remaining;

  typedef equal_to<int3, get_position<acc>::type> test_get_position;
}

MPLLIBS_ADD_TEST(suite, test_for_empty_string)
MPLLIBS_ADD_TEST(suite, test_for_non_empty_string)

MPLLIBS_ADD_TEST(suite, test_get_result)
MPLLIBS_ADD_TEST(suite, test_get_remaining)
MPLLIBS_ADD_TEST(suite, test_get_position)

