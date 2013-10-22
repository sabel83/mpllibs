// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/concat.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/list.hpp>

using mpllibs::metamonad::concat;
using boost::mpl::equal;
using boost::mpl::list;
 
BOOST_AUTO_TEST_CASE(test_join_empty_lists)
{
  BOOST_MPL_ASSERT((equal<list<>, concat<list<>, list<> > >::type));
}

BOOST_AUTO_TEST_CASE(test_join_one_element_list_and_empty_list)
{
  BOOST_MPL_ASSERT((equal<list<int11>, concat<list<int11>, list<> >::type>));
  BOOST_MPL_ASSERT((equal<list<int11>, concat<list<>, list<int11> >::type>));
}

BOOST_AUTO_TEST_CASE(test_join_two_element_lists)
{
  BOOST_MPL_ASSERT((
    equal<list<int0, int1, int11, int13>,
    concat<list<int0, int1>, list<int11, int13> >::type>
  ));
}


