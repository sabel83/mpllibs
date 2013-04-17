// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/eval_let.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

BOOST_AUTO_TEST_CASE(test_lambda)
{
  using boost::mpl::plus;
  using boost::mpl::equal_to;

  using boost::is_same;
  
  using mpllibs::metamonad::lambda;
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::eval_let;
  using mpllibs::metamonad::let;
  using mpllibs::metamonad::_;
  using mpllibs::metamonad::returns;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::apply;

  // test_metaprogramming_value
  BOOST_MPL_ASSERT((
    equal_to<int13, lambda<syntax<plus<int2, int11> > >::type::apply<>::type>
  ));

  // test_no_argument
  BOOST_MPL_ASSERT((
    equal_to<int13, lambda<syntax<plus<int2,int11> > >::apply<>::type>
  ));

  // test_simple_lambda
  BOOST_MPL_ASSERT((
    equal_to<int13, apply<lambda<x, syntax<plus<x, int11> > >, int2>::type>
  ));

  // test_nested_lambda
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<lambda<x, y, syntax<plus<x, y> > >, int2, int11>::type
    >
  ));

  // test_currying
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<apply<lambda<x, y, syntax<plus<x, y> > >, int2>, int11>::type
    >
  ));

  // test_let_and_lambda3_arg
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      eval_syntax<
        let<
          s, syntax<int11>,
          syntax<apply<lambda<x, s, z, syntax<int11> >, int0, int1, int2> >
        >
      >::type
    >
  ));

  // test_unused_arg
  BOOST_MPL_ASSERT((
    is_same<_, apply<lambda<_, syntax<returns<_> > >, int13>::type>
  ));

  // test_laziness
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<lambda<returns<x>, returns<syntax<plus<int2, x> > > >, int11>::type
    >
  ));

  // test_currying_and_lambda
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<
        eval_let<
          y, syntax<int1>,
          syntax<apply<lambda<x, y, syntax<y> >, int11> >
        >,
        int13
      >::type
    >
  ));
}


