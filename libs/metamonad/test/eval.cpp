// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/eval.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/assert.hpp>

using mpllibs::metamonad::returns;

namespace
{
  struct c0;
  struct c1 : returns<c0> {};
  struct c2 : returns<c1> {};
  struct c3 : returns<c2> {};
}

BOOST_AUTO_TEST_CASE(test_eval)
{
  using mpllibs::metamonad::eval;

  using boost::is_same;

  // test_extra_evaluation
  BOOST_MPL_ASSERT((is_same<c0, eval<c2>::type>));

  // test_only_1_extra_evaluation
  BOOST_MPL_ASSERT((is_same<c1, eval<c3>::type>));
}


