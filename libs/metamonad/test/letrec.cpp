// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/letrec.hpp>
#include <mpllibs/metamonad/lambda.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/minus.hpp>

BOOST_AUTO_TEST_CASE(test_letrec)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::equal_to;
  using boost::mpl::minus;
  using boost::mpl::eval_if;
  
  using mpllibs::metamonad::letrec;
  using mpllibs::metamonad::lambda;

  meta_require<
    equal_to<
      int13,
      // name is replaced with a nullary metafunction evaluating to the
      // substituted expression
      letrec<
        x, int13,
        x
      >::type::type
    >
  >(MPLLIBS_HERE, "test_letrec_name");

  meta_require<
    equal_to<int11, letrec<x, int13, int11>::type>
  >(MPLLIBS_HERE, "test_letrec_not_name");
  
  meta_require<
    equal_to<
      int26,
      letrec<
        x, int13,
        lazy_double_value<x>
      >::type
    >
  >(MPLLIBS_HERE, "test_template");

  meta_require<
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
  >(MPLLIBS_HERE, "test_nested_letrec");
  
  meta_require<
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
  >(MPLLIBS_HERE, "test_shadowing");
  
  meta_require<
    equal_to<
      int24,
      letrec<
        x,
        lambda<
          y,
          eval_if<
            lazy_equal_to<y, int0>,
            int1,
            lazy_times<lazy_apply<x, minus<y, int1> >, y>
          >
        >,
        lazy_apply<x, int4>
      >::type::type
    >
  >(MPLLIBS_HERE, "test_recursion");
}



