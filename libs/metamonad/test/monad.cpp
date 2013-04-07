// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/either.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/static_assert.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <iostream>

using boost::mpl::minus;

using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::lambda_c;
using mpllibs::metamonad::right;

namespace
{
  typedef lambda_c<a, right<minus<a, int2> > > minus_2;
}

BOOST_AUTO_TEST_CASE(test_monad)
{
  using boost::mpl::equal_to;
  using boost::mpl::tag;
  
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::left;
  using mpllibs::metamonad::either_tag;

  typedef tag<int13>::type int_tag;
  typedef either_tag<int_tag, int_tag> either;

  // test_return
  BOOST_MPL_ASSERT((equal_to<right<int13>, return_<either, int13>::type>));

  // test_bind_right
  BOOST_MPL_ASSERT((
    equal_to<right<int11>, bind<either, right<int13>, minus_2>::type>
  ));

  // test_bind_left
  BOOST_MPL_ASSERT((
    equal_to<left<int13>, bind<either, left<int13>, minus_2>::type>
  ));

  // test_multi_step_chain
  BOOST_MPL_ASSERT((
    equal_to<
      right<int9>,
      bind<either, bind<either, return_<either, int13>, minus_2>, minus_2>
    >
  ));
}



