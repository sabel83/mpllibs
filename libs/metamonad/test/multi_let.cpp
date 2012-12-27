// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/multi_let.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/pair.hpp>
#include <boost/mpl/map.hpp>

#include <boost/type_traits.hpp>

namespace
{
  struct x;
  struct y;

  template <class A, class B>
  struct some_template;
}

BOOST_AUTO_TEST_CASE(test_multi_let)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::multi_let;

  using boost::mpl::pair;
  using boost::mpl::map;

  using boost::is_same;

  meta_require<
    is_same<int, multi_let<map<pair<x, int> >, x>::type>
  >(MPLLIBS_HERE, "test_setting_value");

  meta_require<
    is_same<x, multi_let<map<>, x>::type>
  >(MPLLIBS_HERE, "test_nothing_to_set");

  meta_require<
    is_same<
      some_template<int, double>,
      multi_let<map<pair<x, int>, pair<y, double> >, some_template<x,y> >::type
    >
  >(MPLLIBS_HERE, "test_multiple_variables");
}


