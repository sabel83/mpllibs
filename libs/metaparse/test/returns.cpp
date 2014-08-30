// Copyright Abel Sinkovics (abel@sinkovics.hu) 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/returns.hpp>

#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_returns)
{
  using mpllibs::metaparse::v1::impl::returns;

  using boost::is_same;

  // test_returns_evaluates_to_its_argument
  BOOST_MPL_ASSERT((is_same<int, returns<int>::type>));
}

