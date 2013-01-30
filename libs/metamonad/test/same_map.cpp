// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include "same_map.hpp"

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/insert.hpp>

BOOST_AUTO_TEST_CASE(test_same_map)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::insert;
  using boost::mpl::map;
  using boost::mpl::pair;

  meta_require<
    not_same_map<
      map<pair<int, double>, pair<char, float> >,
      map<pair<char, float>, pair<double, double> >
    >
  >(MPLLIBS_HERE, "test_different_map");

  meta_require<
    not_same_map<
      map<pair<int, double>, pair<char, float> >,
      map<pair<char, float> >
    >
  >(MPLLIBS_HERE, "test_smaller_map");

  meta_require<
    not_same_map<
      map<pair<int, double> >,
      map<pair<char, float>, pair<int, double> >
    >
  >(MPLLIBS_HERE, "test_bigger_map");

  meta_require<
    same_map<
      map<pair<int, double>, pair<char, float> >,
      map<pair<char, float>, pair<int, double> >
    >
  >(MPLLIBS_HERE, "test_same_map");

  meta_require<
    same_map<map<pair<int, double> >, insert<map<>, pair<int, double> >::type>
  >(MPLLIBS_HERE, "test_same_map_after_insert");
}


