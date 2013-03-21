// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/catch_all.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_catch_all)
{
  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::catch_all;
  using mpllibs::metamonad::lambda_c;
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::_;
  using mpllibs::metamonad::returns;

  using namespace mpllibs::metamonad::name;

  // test_no_exception
  BOOST_MPL_ASSERT((
    equal_to<int13, catch_all<int13, lambda_c<_, int11> >::type>
  ));

  // test_handler_called
  BOOST_MPL_ASSERT((
    equal_to<int11, catch_all<exception<int13>, lambda_c<_, int11> >::type>
  ));

  // test_throw_value_is_passed_to_handler
  BOOST_MPL_ASSERT((
    equal_to<int13, catch_all<exception<int13>, lambda_c<e, e> >::type>
  ));

  // test_handler_argument_is_lazy
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      catch_all<exception<int13>, returns<lambda_c<e, e> > >::type
    >
  ));
}


