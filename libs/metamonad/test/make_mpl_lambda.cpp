// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/make_mpl_lambda.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metamonad::returns;
using boost::mpl::plus;
using boost::mpl::_1;

namespace
{
  template <class N>
  struct build_plus_n : returns<plus<N, _1> > {};
}

BOOST_AUTO_TEST_CASE(test_make_mpl_lambda)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::make_mpl_lambda;
  using mpllibs::metamonad::lazy;

  using boost::mpl::apply_wrap1;
  using boost::mpl::equal_to;

  meta_require<
    equal_to<
      int13,
      apply_wrap1<make_mpl_lambda<plus<_1, int11> >::type, int2>::type
    >
  >(MPLLIBS_HERE, "test_simple_lambda");

  meta_require<
    equal_to<
      int13,
      lazy<apply_wrap1<make_mpl_lambda<build_plus_n<int11> >, int2> >::type
    >
  >(MPLLIBS_HERE, "test_function_returning_lambda");
}


