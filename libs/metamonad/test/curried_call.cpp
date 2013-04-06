// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/curried_call.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::returns;

namespace
{
  template <class A, class B, class C, class D>
  struct some_template : tmp_value<some_template<A, B, C, D> > {};

  template <class A, class B, class C, class D>
  struct returns_some_template : returns<some_template<A, B, C, D> > {};
}

BOOST_AUTO_TEST_CASE(test_curried_call)
{
  using mpllibs::metamonad::curried_call4;
  using mpllibs::metamonad::apply;

  using boost::is_same;

  // test_providing_all_args
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int0, int1, int2, int4>,
      curried_call4<returns_some_template, int0, int1, int2, int4>::type
    >
  ));

  // test_1_extra
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int0, int1, int2, int4>,
      apply<curried_call4<returns_some_template, int0, int1, int2>, int4>::type
    >
  ));

  // test_2_extra
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int0, int1, int2, int4>,
      apply<
        curried_call4<returns_some_template, int0, int1>,
        int2,
        int4
      >::type
    >
  ));

  // test_3_extra
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int0, int1, int2, int4>,
      apply<
        curried_call4<returns_some_template, int0>,
        int1,
        int2,
        int4
      >::type
    >
  ));

  // test_all_extra
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int0, int1, int2, int4>,
      apply<
        curried_call4<returns_some_template>,
        int0,
        int1,
        int2,
        int4
      >::type
    >
  ));

  // test_in_steps
  BOOST_MPL_ASSERT((
    is_same<
      some_template<int0, int1, int2, int4>,
      apply<
        apply<
          apply<apply<curried_call4<returns_some_template>, int0>, int1>,
          int2
        >,
        int4
      >::type
    >
  ));
}



