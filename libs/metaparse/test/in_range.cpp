// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/in_range.hpp>

#include "common.hpp"

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_util_in_range)
{
  using mpllibs::metaparse::util::in_range;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::not_;

  // test_int_in_range
  BOOST_MPL_ASSERT((apply_wrap1<in_range<int10, int13>, int12>));

  // test_lower_bound
  BOOST_MPL_ASSERT((apply_wrap1<in_range<int10, int13>, int10>));

  // test_upper_bound
  BOOST_MPL_ASSERT((apply_wrap1<in_range<int10, int13>, int13>));

  // test_int_not_in_range
  BOOST_MPL_ASSERT((not_<apply_wrap1<in_range<int10, int13>, int14> >));
}

