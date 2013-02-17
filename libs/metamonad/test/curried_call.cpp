// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/curried_call.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/apply_wrap.hpp>

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
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::curried_call4;

  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;
  using boost::mpl::apply_wrap3;
  using boost::mpl::apply_wrap4;

  using boost::is_same;

  meta_require<
    is_same<
      some_template<int0, int1, int2, int4>,
      curried_call4<returns_some_template, int0, int1, int2, int4>::type
    >
  >(MPLLIBS_HERE, "test_providing_all_args");

  meta_require<
    is_same<
      some_template<int0, int1, int2, int4>,
      apply_wrap1<
        curried_call4<returns_some_template, int0, int1, int2>::type,
        int4
      >::type
    >
  >(MPLLIBS_HERE, "test_1_extra");

  meta_require<
    is_same<
      some_template<int0, int1, int2, int4>,
      apply_wrap2<
        curried_call4<returns_some_template, int0, int1>::type,
        int2,
        int4
      >::type
    >
  >(MPLLIBS_HERE, "test_2_extra");

  meta_require<
    is_same<
      some_template<int0, int1, int2, int4>,
      apply_wrap3<
        curried_call4<returns_some_template, int0>::type,
        int1,
        int2,
        int4
      >::type
    >
  >(MPLLIBS_HERE, "test_3_extra");

  meta_require<
    is_same<
      some_template<int0, int1, int2, int4>,
      apply_wrap4<
        curried_call4<returns_some_template>::type,
        int0,
        int1,
        int2,
        int4
      >::type
    >
  >(MPLLIBS_HERE, "test_all_extra");

  meta_require<
    is_same<
      some_template<int0, int1, int2, int4>,
      apply_wrap1<
        apply_wrap1<
          apply_wrap1<
            apply_wrap1<curried_call4<returns_some_template>::type, int0>::type,
            int1
          >::type,
          int2
        >::type,
        int4
      >::type
    >
  >(MPLLIBS_HERE, "test_in_steps");
}



