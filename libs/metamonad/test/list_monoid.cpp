// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/apply.hpp>

BOOST_AUTO_TEST_CASE(test_list_monoid)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::monoid;
  
  using boost::mpl::equal;
  using boost::mpl::list;
  using boost::mpl::apply;

  typedef list<int, double> l_x;
  typedef list<char, long> l_y;
  typedef list<int*, int**, int***> l_z;
  
  typedef monoid<list_tag>::empty mempty;
  typedef monoid<list_tag>::append mappend;
  typedef monoid<list_tag>::concat mconcat;
  
  meta_require<
    equal<l_x, apply<mappend, mempty, l_x>::type>
  >(MPLLIBS_HERE, "test_left_identity");
  meta_require<
    equal<l_x, apply<mappend, l_x, mempty>::type>
  >(MPLLIBS_HERE, "test_right_identity");

  meta_require<
    equal<
      apply<mappend, apply<mappend, l_x, l_y>::type, l_z>::type,
      apply<mappend, l_x, apply<mappend, l_y, l_z>::type>::type
    >
  >(MPLLIBS_HERE, "test_assoc");
}


