// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include "common.hpp"

#include <mpllibs/metaparse/util/is_digit.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_accept_when)
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::accept_when;
  using mpllibs::metaparse::one_char;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;

  using mpllibs::metaparse::util::is_digit;

  using boost::mpl::apply;
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::string;

  typedef string<'fail'> test_error_msg;

  // test_with_text
  BOOST_MPL_ASSERT((
    is_error<
      apply_wrap2<
        accept_when<one_char, is_digit, test_error_msg>,
        str_hello,
        start
      >
    >
  ));
  
  // test_with_number
  BOOST_MPL_ASSERT((
    equal_to<
      get_result<
        apply_wrap2<
          accept_when<one_char, is_digit, test_error_msg>,
          str_1983,
          start
        >
      >::type,
      char_1
    >
  ));

  // test_with_empty_string
  BOOST_MPL_ASSERT((
    is_error<
      apply_wrap2<accept_when<one_char, is_digit, test_error_msg>, str_, start>
    >
  ));
}

