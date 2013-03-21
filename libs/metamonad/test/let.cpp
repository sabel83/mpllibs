// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/eval_guard.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

namespace
{
  template <class A, class B>
  struct some_template;
}

BOOST_AUTO_TEST_CASE(test_let)
{
  using boost::mpl::equal;
  using boost::mpl::equal_to;
  using boost::mpl::plus;
  using boost::mpl::list;
  
  using mpllibs::metamonad::let;
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::matches_c;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::eval_guard;

  using boost::is_same;

  // test_let_name
  BOOST_MPL_ASSERT((
    equal_to<int13, eval_syntax<let<x, syntax<int13>, syntax<x> > >::type>
  ));

  // test_let_not_name
  BOOST_MPL_ASSERT((
    equal_to<int11, eval_syntax<let<x, syntax<int13>, syntax<int11> > >::type>
  ));
  
  // test_template
  BOOST_MPL_ASSERT((
    equal_to<
      int26,
      eval_syntax<let<x, syntax<int13>, syntax<double_value<x> > > >::type
    >
  ));

  // test_let_not_evaluating_its_body
  BOOST_MPL_ASSERT((
    is_same<syntax<int>, let<x, syntax<double>, syntax<int> >::type>
  ));

  // test_case_in_multi_let
  BOOST_MPL_ASSERT((
    is_same<
      syntax<eval_case<int, matches_c<int, some_template<int, double> > > >,
      let<
        x, syntax<double>,
        syntax<eval_case<int, matches_c<int, some_template<int, x> > > >
      >::type
    >
  ));

  // test_list_in_let
  BOOST_MPL_ASSERT((
    equal<
      list<int, double>,
      eval_syntax<let<x, syntax<int>, syntax<list<x, double> > > >::type
    >
  ));

  // test_let_and_eval_guard
  BOOST_MPL_ASSERT((
    is_same<
      syntax<eval_guard<int13> >,
      let<x, syntax<int13>, syntax<eval_guard<x> > >::type
    >
  ));
}



