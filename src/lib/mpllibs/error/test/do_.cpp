// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/do_.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("do_");
  
  template <class a>
  struct minus_2 :
    Right<typename boost::mpl::minus<typename a::value, int2>::type>
  {};

  typedef
    boost::mpl::equal_to<
      Right<int11>,
      DO<Either,
        SET<x, RETURN<Either, int13> >,
        minus_2<x>
      >::type
    >
    TestDo;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      DO<Either,
        SET<x, RETURN<Either, int13> >,
        SET<y, minus_2<x> >,
        minus_2<y>
      >::type
    >
    TestDoThreeSteps;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      DO<Either,
        SET<x, RETURN<Either, int13> >,
        SET<y, minus_2<x> >,
        minus_2<x>,
        minus_2<y>
      >::type
    >
    TestDoTwoCalls;

  typedef
    boost::mpl::equal_to<
      Right<int13>,
      DO<Either,
        RETURN<Either, int11>,
        RETURN<Either, int13>
      >::type
    >
    TestDoTwoReturns;
}

MPLLIBS_ADD_TEST(suite, TestDo)
MPLLIBS_ADD_TEST(suite, TestDoThreeSteps)
MPLLIBS_ADD_TEST(suite, TestDoTwoCalls)
MPLLIBS_ADD_TEST(suite, TestDoTwoReturns)


