// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>

#include <boost/static_assert.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("monad");
  
  typedef
    boost::mpl::equal_to<
      Right<int13>,
      boost::mpl::apply<mpllibs::error::return_<Either>, int13>::type
    >
    TestReturn;

  typedef
    boost::mpl::equal_to<
      Right<int11>,
      mpllibs::error::bind<Right<int13>, minus_2>::type
    >
    TestBindRight;

  typedef
    boost::mpl::equal_to<
      Left<int13>,
      mpllibs::error::bind<Left<int13>, minus_2>::type
    >
    TestBindLeft;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      mpllibs::error::bind<
        mpllibs::error::bind<
          boost::mpl::apply<mpllibs::error::return_<Either>, int13>,
          minus_2
        >,
        minus_2
      >
    >
    TestMultiStepChain;
}

MPLLIBS_ADD_TEST(suite, TestReturn)
MPLLIBS_ADD_TEST(suite, TestBindLeft)
MPLLIBS_ADD_TEST(suite, TestBindRight)
MPLLIBS_ADD_TEST(suite, TestMultiStepChain)



