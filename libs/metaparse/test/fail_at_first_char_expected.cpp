// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail_at_first_char_expected.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/keyword.hpp>

#include "common.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_fail_at_first_char_expected)
{
  using mpllibs::metaparse::fail_at_first_char_expected;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::start;

  typedef mpllibs::metaparse::keyword<str_hello> accept_hello;

  // test_failure_at_first_char_is_ignored
  BOOST_MPL_ASSERT_NOT((
    is_error<fail_at_first_char_expected<accept_hello>::apply<str_ab, start> >
  ));

  // test_no_failure_is_error
  BOOST_MPL_ASSERT((
    is_error<
      fail_at_first_char_expected<accept_hello>::apply<str_hello, start>
    >
  ));

  // test_failure_at_second_char_is_not_ignored
  BOOST_MPL_ASSERT((
    is_error< fail_at_first_char_expected<accept_hello>::apply<str_h, start> >
  ));
}

