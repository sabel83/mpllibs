// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/state.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/pair.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

using boost::mpl::plus;

using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::lazy;
using mpllibs::metamonad::lambda_c;
using mpllibs::metamonad::pair;

using namespace mpllibs::metamonad::name;

namespace
{
  MPLLIBS_METAFUNCTION(plusn, (N))
  ((lambda_c<a, b, lazy<pair<plus<a, N>, plus<b, N> > > >));
}

BOOST_AUTO_TEST_CASE(test_state)
{
  using mpllibs::metamonad::state_tag;
  using mpllibs::metamonad::monad;

  using boost::mpl::equal_to;
  using boost::mpl::apply;
  using boost::mpl::int_;
  using boost::mpl::quote1;

  typedef int_<24> int24;
  typedef int_<14> int14;
  typedef apply<monad<state_tag>::return_, int11>::type return11;
  
  // test_return_value
  BOOST_MPL_ASSERT((equal_to<int11, apply<return11, int13>::type::first>));
  
  // test_return_state
  BOOST_MPL_ASSERT((equal_to<int13, apply<return11, int13>::type::second>));

  // test_bind_value
  BOOST_MPL_ASSERT((
    equal_to<
      int24,
      apply<
        apply<monad<state_tag>::bind, return11, plusn<int13> >::type,
        int1
      >::type::first
    >
  ));

  // test_bind_state
  BOOST_MPL_ASSERT((
    equal_to<
      int14,
      apply<
        apply<monad<state_tag>::bind, return11, plusn<int13> >::type,
        int1
      >::type::second
    >
  ));
}


