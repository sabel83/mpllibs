// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/is_same.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_is_same)
{
  using mpllibs::metamonad::is_same;

  BOOST_MPL_ASSERT((is_same<int13, int13>));
  BOOST_MPL_ASSERT_NOT((is_same<int11, int13>));

  BOOST_MPL_ASSERT((is_same<int13>::type::apply<int13>));
  BOOST_MPL_ASSERT_NOT((is_same<int13>::type::apply<int11>));

  BOOST_MPL_ASSERT((is_same<>::type::apply<int13>::type::apply<int13>));
  BOOST_MPL_ASSERT_NOT((is_same<>::type::apply<int13>::type::apply<int11>));
}


