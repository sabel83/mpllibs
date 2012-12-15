// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>

#include <boost/static_assert.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <iostream>

using boost::mpl::minus;

using mpllibs::metamonad::tmp_value;

namespace
{
  struct minus_2 : tmp_value<minus_2>
  {
    template <class A>
    struct apply : right<typename minus<A, int2>::type> {};
  };
}

BOOST_AUTO_TEST_CASE(test_monad)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;

  meta_require<
    equal_to<right<int13>, return_<either, int13>::type>
  >(MPLLIBS_HERE, "test_return");

  meta_require<
    equal_to<right<int11>, bind<either, right<int13>, minus_2>::type>
  >(MPLLIBS_HERE, "test_bind_right");

  meta_require<
    equal_to<left<int13>, bind<either, left<int13>, minus_2>::type>
  >(MPLLIBS_HERE, "test_bind_left");

  meta_require<
    equal_to<
      right<int9>,
      bind<either, bind<either, return_<either, int13>, minus_2>, minus_2>
    >
  >(MPLLIBS_HERE, "test_multi_step_chain");
}



