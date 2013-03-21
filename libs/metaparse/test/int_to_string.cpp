// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/int_to_string.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_int_to_string)
{
  using mpllibs::metaparse::util::int_to_string;
  
  using boost::mpl::equal;
  using boost::mpl::apply_wrap1;
  using boost::mpl::string;
  using boost::mpl::int_;

  // test0
  BOOST_MPL_ASSERT((
    equal<string<'0'>, apply_wrap1<int_to_string, int_<0> >::type>
  ));

  // test1
  BOOST_MPL_ASSERT((
    equal<string<'1'>, apply_wrap1<int_to_string, int_<1> >::type>
  ));

  // test13
  BOOST_MPL_ASSERT((
    equal<string<'13'>, apply_wrap1<int_to_string, int_<13> >::type>
  ));

  // test_minus_13
  BOOST_MPL_ASSERT((
    equal<string<'-13'>, apply_wrap1<int_to_string, int_<-13> >::type>
  ));
}

