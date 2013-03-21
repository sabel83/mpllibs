// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/unbox.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/let_c.hpp>
#include <mpllibs/metamonad/syntax.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

BOOST_AUTO_TEST_CASE(test_box)
{
  using mpllibs::metamonad::box;
  using mpllibs::metamonad::unbox;
  using mpllibs::metamonad::let_c;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::var;

  using boost::mpl::equal_to;
  using boost::mpl::not_;

  using boost::is_same;

  // test_box_as_nullary_metafunction
  BOOST_MPL_ASSERT((is_same<box<int>, box<int>::type>));

  // test_unboxing
  BOOST_MPL_ASSERT((is_same<int, unbox<box<int> >::type>));

  // test_equality
  BOOST_MPL_ASSERT((equal_to<box<int>, box<int> >));

  // test_unequality
  BOOST_MPL_ASSERT((not_<equal_to<box<int>, box<double> >::type>));

  // test_let
  BOOST_MPL_ASSERT((
    is_same<
      syntax<box<var<int> > >,
      let_c<var<int>, double, box<var<int> > >::type
    >
  ));

  // test_let_with_boxed_value_as_variable
  BOOST_MPL_ASSERT((
    is_same<syntax<double>, let_c<box<int>, double, box<int> >::type>
  ));
}


