// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;

using boost::mpl::apply;
using boost::mpl::equal_to;

namespace
{
  const test_suite suite("digit");

  typedef is_error<apply<digit, str_hello, start> > test_with_text;
  
  typedef
    equal_to<get_result<apply<digit, str_1983, start> >::type, char_1>
    test_with_number;
  
  typedef is_error<apply<digit, str_, start> > test_with_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_with_text)
MPLLIBS_ADD_TEST(suite, test_with_number)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)


