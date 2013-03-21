// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/eval_let.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"


BOOST_AUTO_TEST_CASE(test_eval_let)
{
  using boost::mpl::equal_to;
  using boost::mpl::plus;
  
  using mpllibs::metamonad::eval_let;
  using mpllibs::metamonad::syntax;

  // test_evaluation_of_expression
  BOOST_MPL_ASSERT((
    equal_to<int13, eval_let<x, syntax<int11>, syntax<plus<int2, x> > >::type>
  ));
}



