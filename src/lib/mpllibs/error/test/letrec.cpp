// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/letrec.h>
#include <mpllibs/error/lambda.h>

#include <mpllibs/metatest/test.h>

#include "common.h"

#include <boost/mpl/minus.hpp>

using boost::mpl::equal_to;
using boost::mpl::minus;

using mpllibs::metatest::suite_path;

using mpllibs::error::letrec;
using mpllibs::error::lambda;

namespace
{
  const suite_path suite("letrec");

  typedef
    equal_to<
      int13,
      // name is replaced with a nullary metafunction evaluating to the
      // substituted expression
      letrec<
        x, int13,
        x
      >::type::type
    >
    test_letrec_name;

  typedef equal_to<int11, letrec<x, int13, int11>::type> test_letrec_not_name;
  
  typedef
    equal_to<
      int26,
      letrec<
        x, int13,
        lazy_double_value<x>
      >::type
    >
    test_template;

  typedef
    equal_to<
      int24,
      letrec<
        x, int13,
        letrec<
          y, int11,
          lazy_plus<x, y>
        >::type
      >::type::type
    >
    test_nested_letrec;
  
  typedef
    equal_to<
      int37,
      letrec<
        x, int13,
        double_lazy_plus<
          x,
          letrec<
            x, int11,
            lazy_plus<x, int13>
          >
        >
      >::type::type
    >
    test_shadowing;
  
  typedef
    equal_to<
      int24,
      letrec<
        x,
        lambda<
          y,
          lazy_eval_if<
            lazy_equal_to<y, int0>,
            int1,
            lazy_times<lazy_apply<x, minus<y, int1> >, y>
          >
        >,
        lazy_apply<x, int4>
      >::type::type
    >
    test_recursion;
}

MPLLIBS_ADD_TEST(suite, test_letrec_name)
MPLLIBS_ADD_TEST(suite, test_letrec_not_name)
MPLLIBS_ADD_TEST(suite, test_template)
MPLLIBS_ADD_TEST(suite, test_nested_letrec)
MPLLIBS_ADD_TEST(suite, test_shadowing)
MPLLIBS_ADD_TEST(suite, test_recursion)




