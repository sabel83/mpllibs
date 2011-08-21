// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metatest/test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::list_tag;
using mpllibs::metamonad::monoid;

using boost::mpl::equal;
using boost::mpl::list;
using boost::mpl::apply;

namespace
{
  const suite_path suite = suite_path("list")("monoid");
  
  typedef list<int, double> l_x;
  typedef list<char, long> l_y;
  typedef list<int*, int**, int***> l_z;
  
  typedef monoid<list_tag>::empty mempty;
  typedef monoid<list_tag>::append mappend;
  typedef monoid<list_tag>::concat mconcat;
  
  typedef equal<l_x, apply<mappend, mempty, l_x>::type> test_left_identity;
  typedef equal<l_x, apply<mappend, l_x, mempty>::type> test_right_identity;

  typedef
    equal<
      apply<mappend, apply<mappend, l_x, l_y>::type, l_z>::type,
      apply<mappend, l_x, apply<mappend, l_y, l_z>::type>::type
    >
    test_assoc;
}

MPLLIBS_ADD_TEST(suite, test_left_identity)
MPLLIBS_ADD_TEST(suite, test_right_identity)
MPLLIBS_ADD_TEST(suite, test_assoc)


