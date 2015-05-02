// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_message.hpp>

#include <mpllibs/metaparse/error/digit_expected.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits/is_same.hpp>

BOOST_AUTO_TEST_CASE(test_digit)
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::digit;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::get_message;

  using mpllibs::metaparse::error::digit_expected;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;

  using boost::is_same;

  // test_with_text
  BOOST_MPL_ASSERT((is_error<apply_wrap2<digit, str_hello, start> >));
  
  // test_with_number
  BOOST_MPL_ASSERT((
    equal_to<get_result<apply_wrap2<digit, str_1983, start> >::type, char_1>
  ));
  
  // test_with_empty_string
  BOOST_MPL_ASSERT((is_error<apply_wrap2<digit, str_, start> >));

  // test_error_message_with_empty_string
  BOOST_MPL_ASSERT((
    is_same<digit_expected, get_message<apply_wrap2<digit, str_, start> >::type>
  ));
}

