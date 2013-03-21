// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

BOOST_AUTO_TEST_CASE(test_already_lazy)
{
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::already_lazy;
  using mpllibs::metamonad::returns;
  
  using boost::mpl::equal_to;
  using boost::mpl::false_;
  using boost::mpl::divides;

  using boost::is_same;

  // test_custom_eval_if
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      lazy<
        custom_eval_if<
          false_,
          already_lazy<breaking_expr>,
          already_lazy<divides<int26, int2> >
        >
      >::type
    >
  ));

  // test_custom_eval_if_with_lazy_expression_as_selected_case
  BOOST_MPL_ASSERT((
    equal_to<
      int26,
      lazy<
        custom_eval_if<
          false_,
          already_lazy<breaking_expr>,
          already_lazy<lazy<non_lazy_plus<returns13, returns13> > >
        >
      >::type
    >
  ));

  // test_outside_of_lazy
  BOOST_MPL_ASSERT((is_same<double, already_lazy<returns<double> >::type>));
}


