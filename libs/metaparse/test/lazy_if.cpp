// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/lazy_if.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_util_lazy_if)
{
  using mpllibs::metaparse::util::lazy_if;
  
  using boost::mpl::equal_to;
  using boost::mpl::true_;
  using boost::mpl::false_;
  using boost::mpl::eval_if;

  // evaluated_condition
  BOOST_MPL_ASSERT((lazy_if<equal_to<int13, int13>, true_, false_>));
  
  // not_evaluated_condition
  BOOST_MPL_ASSERT((
    eval_if<false_, lazy_if<can_not_be_instantiated, int11, int13>, true_>
  ));
}



