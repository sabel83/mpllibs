// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/apply.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.hpp"

using mpllibs::metamonad::tmp_value;

using boost::mpl::plus;

namespace
{
  struct add : tmp_value<add>
  {
    template <class A, class B>
    struct apply : plus<A, B> {};
  };

  struct id : tmp_value<id>
  {
    template <class A>
    struct apply : A {};
  };
}

BOOST_AUTO_TEST_CASE(test_apply)
{
  using mpllibs::metamonad::apply;
  using mpllibs::metamonad::returns;

  using boost::mpl::equal_to;

  BOOST_MPL_ASSERT((equal_to<int13, apply<add, int11, int2> >));

  BOOST_MPL_ASSERT((
    equal_to<int13, apply<returns<add>, returns<int11>, returns<int2> > >
  ));
}


