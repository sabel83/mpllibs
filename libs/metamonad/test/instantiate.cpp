// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/instantiate.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

using mpllibs::metamonad::tmp_value;

namespace
{
  template <class A, class B>
  struct some_template : tmp_value<some_template<A, B> > {};
}

BOOST_AUTO_TEST_CASE(test_instantiate)
{
  using mpllibs::metamonad::instantiate2;
  using mpllibs::metamonad::apply;

  using boost::mpl::vector;
  using boost::mpl::na;

  using boost::is_same;

  // test_instantiation
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int, double>,
      apply<instantiate2<some_template>, vector<int, double> >::type
    >
  ));

  // test_instantiation_with_na
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int, na>,
      apply<instantiate2<some_template>, vector<int> >::type
    >
  ));
}


