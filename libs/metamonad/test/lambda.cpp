// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/lambda.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>

BOOST_AUTO_TEST_CASE(test_lambda)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::apply;
  using boost::mpl::plus;
  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::lambda;

  meta_require<
    equal_to<int13, apply<lambda<x, plus<x, int11> >, int2>::type>
  >(MPLLIBS_HERE, "test_simple_lambda");

  meta_require<
    equal_to<
      int13,
      lazy_apply<apply<lambda<x, lambda<y, plus<x, y> > >, int2>, int11>::type
    >
  >(MPLLIBS_HERE, "test_nested_lambda");
}


