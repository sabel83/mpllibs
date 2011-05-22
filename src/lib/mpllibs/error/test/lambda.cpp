// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/lambda.hpp>

#include <mpllibs/metatest/test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>

using boost::mpl::apply;
using boost::mpl::plus;
using boost::mpl::equal_to;

using mpllibs::metatest::suite_path;

using mpllibs::error::lambda;

namespace
{
  const suite_path suite("lambda");

  typedef
    equal_to<int13, apply<lambda<x, plus<x, int11> >, int2>::type>
    test_simple_lambda;

  typedef
    equal_to<
      int13,
      lazy_apply<apply<lambda<x, lambda<y, plus<x, y> > >, int2>, int11>::type
    >
    test_nested_lambda;
}

MPLLIBS_ADD_TEST(suite, test_simple_lambda)
MPLLIBS_ADD_TEST(suite, test_nested_lambda)



