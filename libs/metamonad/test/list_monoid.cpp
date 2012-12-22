// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metamonad/mempty.hpp>
#include <mpllibs/metamonad/mappend.hpp>
#include <mpllibs/metamonad/mconcat.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>

BOOST_AUTO_TEST_CASE(test_list_monoid)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::mempty;
  using mpllibs::metamonad::mappend;
  using mpllibs::metamonad::mconcat;
  
  using boost::mpl::equal;
  using boost::mpl::list;

  typedef list<int, double> l_x;
  typedef list<char, long> l_y;
  typedef list<int*, int**, int***> l_z;
  
  meta_require<
    equal<l_x, mappend<list_tag, mempty<list_tag>::type, l_x>::type>
  >(MPLLIBS_HERE, "test_left_identity");
  meta_require<
    equal<l_x, mappend<list_tag, l_x, mempty<list_tag>::type>::type>
  >(MPLLIBS_HERE, "test_right_identity");

  meta_require<
    equal<
      mappend<list_tag, mappend<list_tag, l_x, l_y>::type, l_z>::type,
      mappend<list_tag, l_x, mappend<list_tag, l_y, l_z>::type>::type
    >
  >(MPLLIBS_HERE, "test_assoc");
}


