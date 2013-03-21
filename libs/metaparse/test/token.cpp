// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  using mpllibs::metaparse::keyword;
  using mpllibs::metaparse::token;

  using boost::mpl::list_c;

  typedef list_c<char, 'h', 'e', 'l', 'l', 'o', ' ', '\t'> str_hello_t;

  typedef keyword<str_hello, int13> test_parser;
  typedef token<test_parser> a_test_token;
}

BOOST_AUTO_TEST_CASE(test_token)
{
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_remaining;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal;

  // test_no_space
  BOOST_MPL_ASSERT((
    equal_to<
      get_result<apply_wrap2<a_test_token, str_hello, start> >::type,
      get_result<apply_wrap2<test_parser, str_hello, start> >::type
    >
  ));

  // test_spaces
  BOOST_MPL_ASSERT((
    equal_to<
      get_result<apply_wrap2<a_test_token, str_hello_t, start> >::type,
      get_result<apply_wrap2<test_parser, str_hello, start> >::type
    >
  ));

  // test_spaces_consumed
  BOOST_MPL_ASSERT((
    equal<
      get_remaining<apply_wrap2<a_test_token, str_hello_t, start> >::type,
      str_
    >
  ));

  // test_fail
  BOOST_MPL_ASSERT((is_error<apply_wrap2<a_test_token, str_, start> >));
}


