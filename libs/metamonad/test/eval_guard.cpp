// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/eval_guard.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_eval_guard)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::eval_guard;
  using mpllibs::metamonad::lazy;

  using boost::is_same;

  using namespace mpllibs::metamonad::name;

  meta_require<
    is_same<eval_guard<int>, eval_guard<int>::type>
  >(MPLLIBS_HERE, "test_eval_guard_as_nullary_metafunction");

  meta_require<
    is_same<eval_guard<int>, lazy<eval_guard<int> >::type>
  >(MPLLIBS_HERE, "test_lazy");
}


