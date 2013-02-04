// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/match_c.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>

#include "common.hpp"
#include "same_map.hpp"
#include "is_empty.hpp"

using mpllibs::metamonad::tmp_value;

BOOST_AUTO_TEST_CASE(test_map_insert)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::impl::map_insert;

  using boost::mpl::map;
  using boost::mpl::pair;

  using boost::is_same;

  meta_require<
    same_map<map<pair<int1, int2> >, map_insert<map<>, pair<int1, int2> >::type>
  >(MPLLIBS_HERE, "test_inserting_into_empty_map");

  meta_require<
    same_map<
      map<pair<int1, int2>, pair<int11, int13> >,
      map_insert<map<pair<int11, int13> >, pair<int1, int2> >::type
    >
  >(MPLLIBS_HERE, "test_inserting_into_non_empty_map");

  meta_require<
    same_map<
      map<pair<int1, int2> >,
      map_insert<map<pair<int1, int2> >, pair<int1, int2> >::type
    >
  >(MPLLIBS_HERE, "test_reinserting_element");

  meta_require<
    same_map<
      map<pair<int1, int2>, pair<int11, int13> >,
      map_insert<
        map<pair<int11, int13>, pair<int1, int2> >,
        pair<int1, int2>
      >::type
    >
  >(MPLLIBS_HERE, "test_reinserting_with_two_elements");

  meta_require<
    same_map<
      map<pair<int1, int2> >,
      map_insert<map<>, pair<int1, int2> >::type::type
    >
  >(MPLLIBS_HERE, "test_result_of_insert_is_metaprogramming_value");
}


