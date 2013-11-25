// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/concat_map.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>

using boost::mpl::list;
using mpllibs::metamonad::concat_map;
using boost::mpl::equal;
 
using mpllibs::metamonad::lambda_c;
using namespace mpllibs::metamonad::name;

namespace
{
  typedef lambda_c<t, list<t, t> > twice;
}

BOOST_AUTO_TEST_CASE(test_concat_map_empty_list)
{
  BOOST_MPL_ASSERT((equal<concat_map<list<>, twice>::type, list<> >));
}

BOOST_AUTO_TEST_CASE(test_concat_map_one_element_list)
{
  BOOST_MPL_ASSERT((
    equal<concat_map<list<int11>, twice>::type, list<int11, int11> >
  ));
}

BOOST_AUTO_TEST_CASE(test_concat_map_two_element_list)
{
  BOOST_MPL_ASSERT((
    equal<
      concat_map<list<int11, int13>, twice>::type,
      list<int11, int11, int13, int13>
    >
  ));
}


