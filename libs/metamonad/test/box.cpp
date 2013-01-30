// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/unbox.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/let_c.hpp>
#include <mpllibs/metamonad/syntax.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/not.hpp>

#include <boost/type_traits.hpp>

BOOST_AUTO_TEST_CASE(test_box)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::box;
  using mpllibs::metamonad::unbox;
  using mpllibs::metamonad::let_c;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::var;

  using boost::mpl::equal_to;
  using boost::mpl::not_;

  using boost::is_same;

  meta_require<
    is_same<box<int>, box<int>::type>
  >(MPLLIBS_HERE, "test_box_as_nullary_metafunction");

  meta_require<
    is_same<int, unbox<box<int> >::type>
  >(MPLLIBS_HERE, "test_unboxing");

  meta_require<
    equal_to<box<int>, box<int> >
  >(MPLLIBS_HERE, "test_equality");

  meta_require<
    not_<equal_to<box<int>, box<double> >::type>
  >(MPLLIBS_HERE, "test_unequality");

  meta_require<
    is_same<
      syntax<box<var<int> > >,
      let_c<var<int>, double, box<var<int> > >::type
    >
  >(MPLLIBS_HERE, "test_let");

  meta_require<
    is_same<syntax<double>, let_c<box<int>, double, box<int> >::type>
  >(MPLLIBS_HERE, "test_let_with_boxed_value_as_variable");
}


