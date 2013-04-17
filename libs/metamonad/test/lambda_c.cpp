// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/eval_let.hpp>
#include <mpllibs/metamonad/let.hpp>
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

BOOST_AUTO_TEST_CASE(test_lambda_c)
{
  using boost::mpl::plus;
  using boost::mpl::equal_to;

  using boost::is_same;
  
  using mpllibs::metamonad::lambda_c;
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
    equal_to<int13, lambda_c<plus<int2, int11> >::type::apply<>::type>
  ));

  // test_no_argument
  BOOST_MPL_ASSERT((
    equal_to<int13, lambda_c<plus<int2, int11> >::apply<>::type>
  ));

  // test_simple_lambda
  BOOST_MPL_ASSERT((
    equal_to<int13, apply<lambda_c<x, plus<x, int11> >, int2>::type>
  ));

  // test_nested_lambda
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<lambda_c<x, y, plus<x, y> >, int2, int11>::type
    >
  ));

  // test_multiple_arguments
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<apply<lambda_c<x, lambda_c<y, plus<x, y> > >, int2>, int11>::type
    >
  ));

  // test_currying
  BOOST_MPL_ASSERT((
    equal_to<int13, apply<apply<lambda_c<x, y, plus<x,y> >, int2>, int11>::type>
  ));

  // test_let_and_lambda_body
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      apply<
        eval_syntax<let<a, syntax<int11>, syntax<lambda_c<b, a> > > >,
        int13
      >::type
    >
  ));

  // test_let_and_lambda3_body
  BOOST_MPL_ASSERT((
    equal_to<
      int1,
      eval_syntax<
        let<
          s, syntax<int11>,
          syntax<apply<lambda_c<x, s, z, s>, int0, int1, int2> >
        >
      >::type
    >
  ));

  // test_let_and_lambda3_arg
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      eval_syntax<
        let<
          s, syntax<int11>,
          syntax<apply<lambda_c<x, s, z, int11>, int0, int1, int2> >
        >
      >::type
    >
  ));

  // test_nested_lambda
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<apply<lambda_c<a, lambda_c<b, a> >, int13>, int11>::type
    >
  ));

  // test_unused_arg
  BOOST_MPL_ASSERT((is_same<_, apply<lambda_c<_, returns<_> >, int13>::type>));

  // test_parameter_hiding
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<lambda_c<e, apply<lambda_c<e, e>::type, e> >, int13>::type
    >
  ));

  // test_currying_and_lambda
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<
        eval_let<
          y, syntax<int1>,
          syntax<apply<lambda_c<x, y, y>, int11> >
        >,
        int13
      >::type
    >
  ));
}


