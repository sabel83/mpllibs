// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_if_)
{
  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::if_;
  using mpllibs::metamonad::returns;

  typedef returns<boost::mpl::true_> returns_true;
  typedef returns<boost::mpl::false_> returns_false;

  typedef returns<int11> returns11;
  typedef returns<int13> returns13;

  // test_chooses_true_case
  BOOST_MPL_ASSERT((
    equal_to<int11, if_<returns_true, returns11, returns13>::type>
  ));

  // test_chooses_false_case
  BOOST_MPL_ASSERT((
    equal_to<int13, if_<returns_false, returns11, returns13>::type>
  ));
}


