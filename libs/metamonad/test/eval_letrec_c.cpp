// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/eval_letrec_c.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"


BOOST_AUTO_TEST_CASE(test_eval_letrec_c)
{
  using boost::mpl::equal_to;
  using boost::mpl::plus;
  
  using mpllibs::metamonad::eval_letrec_c;
  using mpllibs::metamonad::lazy;

  // test_evaluation_of_expression
  BOOST_MPL_ASSERT((
    equal_to<int13, eval_letrec_c<x, int11, lazy<plus<int2, x> > >::type>
  ));
}



