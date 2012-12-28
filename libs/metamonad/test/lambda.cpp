// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/let.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/apply_wrap.hpp>

BOOST_AUTO_TEST_CASE(test_lambda)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::apply;
  using boost::mpl::apply_wrap3;
  using boost::mpl::plus;
  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::lambda;
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::let;

  meta_require<
    equal_to<int13, lambda<plus<int2, int11> >::type>
  >(MPLLIBS_HERE, "test_no_argument");

  meta_require<
    equal_to<int13, apply<lambda<x, plus<x, int11> >, int2>::type>
  >(MPLLIBS_HERE, "test_simple_lambda");

  meta_require<
    equal_to<
      int13,
      apply<lambda<x, y, plus<x, y> >, int2, int11>::type
    >
  >(MPLLIBS_HERE, "test_nested_lambda");

  meta_require<
    equal_to<
      int13,
      lazy_apply<apply<lambda<x, lambda<y, plus<x, y> > >, int2>, int11>::type
    >
  >(MPLLIBS_HERE, "test_multiple_arguments");

  meta_require<
    equal_to<
      int13,
      lazy_apply<apply<lambda<x, y, plus<x, y> >, int2>, int11>::type
    >
  >(MPLLIBS_HERE, "test_currying");

  meta_require<
    equal_to<
      int1,
      let<
        s, int11,
        apply_wrap3<lambda<x, s, z, s>, int0, int1, int2>
      >::type::type
    >
  >(MPLLIBS_HERE, "test_let_and_lambda_body");

  meta_require<
    equal_to<
      int11,
      let<
        s, int11,
        apply_wrap3<lambda<x, s, z, int11>, int0, int1, int2>
      >::type::type
    >
  >(MPLLIBS_HERE, "test_let_and_lambda_arg");
}


