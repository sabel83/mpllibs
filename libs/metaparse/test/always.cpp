// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::always;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal_to;
using boost::mpl::apply_wrap2;

namespace
{
  const suite_path suite("always");
  
  typedef always<digit, int13> always_digit_13;

  typedef has_type<always_digit_13> test_has_type;

  typedef
    equal_to<
      get_result<apply_wrap2<always_digit_13, str_1, start> >::type,
      int13
    >
    test_result;
  
  typedef is_error<apply_wrap2<always_digit_13, str_a, start> > test_fail;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_result)
MPLLIBS_ADD_TEST(suite, test_fail)

