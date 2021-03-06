// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_eval_syntax)
{
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::returns;

  using boost::mpl::equal_to;
  using boost::mpl::plus;

  // test_evaluating_a_syntax
  BOOST_MPL_ASSERT((
    equal_to<int13, eval_syntax<syntax<plus<int11, int2> > >::type>
  ));

  // test_laziness_of_eval_syntax
  BOOST_MPL_ASSERT((
    equal_to<int13, eval_syntax<returns<syntax<plus<int11, int2> > > >::type>
  ));
}


