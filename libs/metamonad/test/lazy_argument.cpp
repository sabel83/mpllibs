// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lazy_argument.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/assert.hpp>

BOOST_AUTO_TEST_CASE(test_lazy_argument)
{
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::lazy_argument;
  
  using boost::mpl::equal_to;
  using boost::mpl::false_;

  //test_custom_eval_if_with_lazy_expression_as_selected_case_with_lazy_argument
  BOOST_MPL_ASSERT((
    equal_to<
      int26,
      lazy<
        custom_eval_if<
          false_,
          lazy_argument<breaking_expr>,
          lazy_argument<non_lazy_plus<returns13, returns13> >
        >
      >::type
    >
  ));
}


