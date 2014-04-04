// Copyright Abel Sinkovics (abel@sinkovics.hu) 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/start.hpp>

#include "common.hpp"

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_fail_tag)
{
  using mpllibs::metaparse::fail;
  using mpllibs::metaparse::get_message;
  using mpllibs::metaparse::get_position;
  using mpllibs::metaparse::start;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  using boost::is_same;

  typedef fail<test_failure> p;
  typedef apply_wrap2<p, str_hello, start> failed_result;

  // test_getting_message_back
  BOOST_MPL_ASSERT((is_same<test_failure, get_message<failed_result>::type>));

  // test_getting_position
  BOOST_MPL_ASSERT((equal_to<start, get_position<failed_result>::type>));
}

