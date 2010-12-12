// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/letrec.h>
#include <mpllibs/error/lambda.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include "common.h"

#include <boost/mpl/minus.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("letrec");

  typedef
    boost::mpl::equal_to<
      int13,
      // name is replaced with a nullary metafunction evaluating to the
      // substituted expression
      mpllibs::error::letrec<x, int13, x>::type::type
    >
    TestLetrecName;

  typedef
    boost::mpl::equal_to<int11, mpllibs::error::letrec<x, int13, int11>::type>
    TestLetrecNotName;
  
  typedef
    boost::mpl::equal_to<
      int26,
      mpllibs::error::letrec<x, int13, lazy_double_value<x> >::type
    >
    TestTemplate;

  typedef
    boost::mpl::equal_to<
      int24,
      mpllibs::error::letrec<
        x, int13,
        mpllibs::error::letrec<y, int11, lazy_plus<x, y> >::type
      >::type::type
    >
    TestNestedLetrec;
  
  typedef
    boost::mpl::equal_to<
      int37,
      mpllibs::error::letrec<
        x, int13,
        double_lazy_plus<
          x,
          mpllibs::error::letrec<x, int11, lazy_plus<x, int13> >
        >
      >::type::type
    >
    TestShadowing;
  
  typedef
    boost::mpl::equal_to<
      int24,
      mpllibs::error::letrec<
        x,
        mpllibs::error::lambda<
          y,
          lazy_eval_if<
            lazy_equal_to<y, int0>,
            int1,
            lazy_times<lazy_apply<x, boost::mpl::minus<y, int1> >, y>
          >
        >,
        lazy_apply<x, int4>
      >::type::type
    >
    TestRecursion;
}

MPLLIBS_ADD_TEST(suite, TestLetrecName)
MPLLIBS_ADD_TEST(suite, TestLetrecNotName)
MPLLIBS_ADD_TEST(suite, TestTemplate)
MPLLIBS_ADD_TEST(suite, TestNestedLetrec)
MPLLIBS_ADD_TEST(suite, TestShadowing)
MPLLIBS_ADD_TEST(suite, TestRecursion)




