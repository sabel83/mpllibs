// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/pair.hpp>
#include <mpllibs/metamonad/first.hpp>
#include <mpllibs/metamonad/second.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_pair)
{
  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::pair;
  using mpllibs::metamonad::first;
  using mpllibs::metamonad::second;
  using mpllibs::metamonad::returns;

  typedef returns<int11> returns11;
  typedef returns<int13> returns13;

  // test_first
  BOOST_MPL_ASSERT((equal_to<int11, first<pair<returns11, returns13> >::type>));

  // test_second
  BOOST_MPL_ASSERT((equal_to<int13, second<pair<returns11,returns13> >::type>));

  // test_currying1
  BOOST_MPL_ASSERT((
    equal_to<int11, first<pair<returns11>::type::apply<returns13> >::type>
  ));

  // test_currying2
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      first<pair<>::type::apply<returns11>::type::apply<returns13> >::type
    >
  ));
}


