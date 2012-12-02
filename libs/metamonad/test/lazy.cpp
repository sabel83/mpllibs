// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>

namespace
{
  using boost::mpl::eval_if;

  struct returns13
  {
    typedef int13 type;
  };

  template <class A, class B>
  struct non_lazy_plus : boost::mpl::int_<A::value + B::value> {};

  template <class T>
  struct always13 : returns13 {};

  template <class C, class T, class F>
  struct custom_eval_if : eval_if<C, T, F> {};
}

BOOST_AUTO_TEST_CASE(test_lazy)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::already_lazy;
  
  using boost::mpl::equal_to;
  using boost::mpl::divides;
  using boost::mpl::if_;
  using boost::mpl::false_;

  typedef divides<int1, int0> breaking_expr;

  meta_require<
    equal_to<int13, lazy<divides<int26, int2> >::type>
  >(MPLLIBS_HERE, "test_evaluation");

  meta_require<
    equal_to<int26, lazy<non_lazy_plus<returns13, returns13> >::type>
  >(MPLLIBS_HERE, "test_lazyness");

  meta_require<
    equal_to<
      int13,
      lazy<eval_if<false_, breaking_expr, divides<int26, int2> > >::type
    >
  >(MPLLIBS_HERE, "test_eval_if");

  meta_require<
    equal_to<
      int13,
      lazy<if_<false_, breaking_expr, divides<int26, int2> > >::type::type
    >
  >(MPLLIBS_HERE, "test_if");

  meta_require<
    equal_to<
      int13,
      lazy<
        custom_eval_if<
          false_,
          already_lazy<breaking_expr>,
          already_lazy<divides<int26, int2> >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_custom_eval_if");

}


