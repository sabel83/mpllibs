// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/lambda.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include "common.h"

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("lambda");

  typedef
    boost::mpl::equal_to<
      int13,
      boost::mpl::apply<
        mpllibs::error::lambda<x, boost::mpl::plus<x, int11> >,
        int2
      >::type
    >
    TestSimpleLambda;

  typedef
    boost::mpl::equal_to<
      int13,
      lazy_apply<
        boost::mpl::apply<
          mpllibs::error::lambda<
            x,
            mpllibs::error::lambda<y, boost::mpl::plus<x, y> >
          >,
          int2
        >,
        int11
      >::type
    >
    TestNestedLambda;
}

MPLLIBS_ADD_TEST(suite, TestSimpleLambda)
MPLLIBS_ADD_TEST(suite, TestNestedLambda)



