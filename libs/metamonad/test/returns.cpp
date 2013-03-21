// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/assert.hpp>

namespace
{
  struct has_no_type {};
}

BOOST_AUTO_TEST_CASE(test_returns)
{
  using mpllibs::metamonad::returns;
  using boost::is_same;

  // test_returns
  BOOST_MPL_ASSERT((is_same<has_no_type, returns<has_no_type>::type>));
}


