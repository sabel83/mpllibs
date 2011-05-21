// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/always.h>
#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::always;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const suite_path suite("always");
  
  typedef always<digit, int13> always_digit_13;

  typedef
    equal_to<get_result<apply<always_digit_13, str_1, start> >::type, int13>
    test_result;
  
  typedef is_error<apply<always_digit_13, str_a, start> > test_fail;
}

MPLLIBS_ADD_TEST(suite, test_result)
MPLLIBS_ADD_TEST(suite, test_fail)

