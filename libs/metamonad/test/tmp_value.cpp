// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/assert.hpp>

namespace
{
  using mpllibs::metamonad::tmp_value;

  struct test_tag : tmp_value<test_tag> {};

  struct test_value : tmp_value<test_value> {};

  struct test_value_with_tag : tmp_value<test_value_with_tag, test_tag> {};
}

BOOST_AUTO_TEST_CASE(test_tmp_value)
{
  using mpllibs::metamonad::tmp_value;
  using boost::is_same;

  // test_value_becomes_nullary_metafunction
  BOOST_MPL_ASSERT((is_same<test_value, test_value::type>));

  // test_value_with_tag_becomes_nullary_metafunction
  BOOST_MPL_ASSERT((is_same<test_value_with_tag, test_value_with_tag::type>));

  // test_value_with_tag_has_tag
  BOOST_MPL_ASSERT((is_same<test_tag, test_value_with_tag::tag>));
}


