// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/letrec.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/minus.hpp>
#include <boost/mpl/assert.hpp>

BOOST_AUTO_TEST_CASE(test_letrec)
{
  using boost::mpl::equal_to;
  using boost::mpl::minus;
  
  using mpllibs::metamonad::letrec;
  using mpllibs::metamonad::if_;
  using mpllibs::metamonad::lambda_c;
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::apply;

  // name is replaced with a nullary metafunction evaluating to the
  // substituted expression
  // test_letrec_name
  BOOST_MPL_ASSERT((
    equal_to<int13, eval_syntax<letrec<x, syntax<int13>, syntax<x> > >::type>
  ));

  // test_letrec_not_name
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      eval_syntax<letrec<x, syntax<int13>, syntax<int11> > >::type
    >
  ));
  
  // test_template
  BOOST_MPL_ASSERT((
    equal_to<
      int26,
      eval_syntax<
        letrec<x, syntax<int13>, syntax<lazy_double_value<x> > >
      >::type
    >
  ));

  // test_recursion
  BOOST_MPL_ASSERT((
    equal_to<
      int24,
      eval_syntax<
        letrec<
          x,
          syntax<
            lambda_c<
              y,
              if_<
                lazy_equal_to<y, int0>,
                int1,
                lazy_times<apply<x, minus<y, int1> >, y>
              >
            >
          >,
          syntax<apply<x, int4> >
        >
      >::type
    >
  ));

  // test_letrec_lazy
  BOOST_MPL_ASSERT((
    equal_to<
      int11,
      eval_syntax<
        letrec<x, syntax<int2>, syntax<lazy<minus<int13, x> > > >
      >::type
    >
  ));
}



