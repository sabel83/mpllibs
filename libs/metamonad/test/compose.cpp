// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/compose.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include "common.hpp"

#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  using boost::mpl::plus;
  using boost::mpl::times;

  MPLLIBS_METAFUNCTION(inc, (N)) (( plus<N, int1> ));
  MPLLIBS_METAFUNCTION(take_first, (A)(B)) (( A ));
}

BOOST_AUTO_TEST_CASE(test_compose)
{
  using mpllibs::metamonad::compose;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  
  // test_same_function_twice
  BOOST_MPL_ASSERT((
    equal_to<apply_wrap1<compose<inc<>, inc<> >, int1>::type, int3>
  ));

  // test_same_function_five_times
  BOOST_MPL_ASSERT((
    equal_to<
      apply_wrap1<compose<inc<>, inc<>, inc<>, inc<>, inc<> >, int1>::type,
      int6
    >
  ));

  // test_order
  BOOST_MPL_ASSERT((
    equal_to<apply_wrap1<compose<double_value<>, inc<> >, int13>::type, int28>
  ));

  // test_two_arguments_for_the_first_function
  BOOST_MPL_ASSERT((
    equal_to<
      apply_wrap2<compose<double_value<>, take_first<> >, int1, int3>::type,
      int2
    >
  ));
}


