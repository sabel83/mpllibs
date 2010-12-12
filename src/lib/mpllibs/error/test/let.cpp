// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/let.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("let");

  typedef
    boost::mpl::equal_to<int13, mpllibs::error::let<x, int13, x>::type>
    TestLetName;

  typedef
    boost::mpl::equal_to<int11, mpllibs::error::let<x, int13, int11>::type>
    TestLetNotName;
  
  typedef
    boost::mpl::equal_to<
      int26,
      mpllibs::error::let<x, int13, double_value<x> >::type
    >
    TestTemplate;

  typedef
    boost::mpl::equal_to<
      int24,
      mpllibs::error::let<
        x, int13,
        mpllibs::error::let<y, int11, boost::mpl::plus<x, y> >::type
      >::type::type
    >
    TestNestedLet;
  
  typedef
    boost::mpl::equal_to<
      int37,
      mpllibs::error::let<
        x, int13,
        double_lazy_plus<
          x,
          mpllibs::error::let<x, int11, boost::mpl::plus<x, int13> >
        >
      >::type::type
    >
    TestShadowing;
}

MPLLIBS_ADD_TEST(suite, TestLetName)
MPLLIBS_ADD_TEST(suite, TestLetNotName)
MPLLIBS_ADD_TEST(suite, TestTemplate)
MPLLIBS_ADD_TEST(suite, TestNestedLet)
MPLLIBS_ADD_TEST(suite, TestShadowing)




