// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/match_c.hpp>
#include <mpllibs/metamonad/pair.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"
#include "same_map.hpp"
#include "is_empty.hpp"

using mpllibs::metamonad::tmp_value;

BOOST_AUTO_TEST_CASE(test_map_insert)
{
  using mpllibs::metamonad::impl::map_insert;
  using mpllibs::metamonad::pair;

  using boost::mpl::map;

  using boost::is_same;

  // test_inserting_into_empty_map
  BOOST_MPL_ASSERT((
    same_map<map<pair<int1, int2> >, map_insert<map<>, pair<int1, int2> >::type>
  ));

  // test_inserting_into_non_empty_map
  BOOST_MPL_ASSERT((
    same_map<
      map<pair<int1, int2>, pair<int11, int13> >,
      map_insert<map<pair<int11, int13> >, pair<int1, int2> >::type
    >
  ));

  // test_reinserting_element
  BOOST_MPL_ASSERT((
    same_map<
      map<pair<int1, int2> >,
      map_insert<map<pair<int1, int2> >, pair<int1, int2> >::type
    >
  ));

  // test_reinserting_with_two_elements
  BOOST_MPL_ASSERT((
    same_map<
      map<pair<int1, int2>, pair<int11, int13> >,
      map_insert<
        map<pair<int11, int13>, pair<int1, int2> >,
        pair<int1, int2>
      >::type
    >
  ));

  // test_result_of_insert_is_metaprogramming_value
  BOOST_MPL_ASSERT((
    same_map<
      map<pair<int1, int2> >,
      map_insert<map<>, pair<int1, int2> >::type::type
    >
  ));
}


