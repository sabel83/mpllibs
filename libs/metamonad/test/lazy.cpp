// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/int.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>

using mpllibs::metamonad::returns;

namespace
{
  MPLLIBS_METAFUNCTION(always13, (T)) ((returns13));

  struct hidden_result
  {
    typedef int13 the_result;
    // no ::type
  };

  struct can_be_evaluated_only_once : returns<hidden_result> {};
}

BOOST_AUTO_TEST_CASE(test_lazy)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::lazy;
  
  using boost::mpl::equal_to;
  using boost::mpl::divides;
  using boost::mpl::if_;
  using boost::mpl::false_;

  meta_require<
    equal_to<int13, lazy<divides<int26, int2> >::type>
  >(MPLLIBS_HERE, "test_evaluation");

  meta_require<
    equal_to<int26, lazy<non_lazy_plus<returns13, returns13> >::type>
  >(MPLLIBS_HERE, "test_lazyness");

  meta_require<
    equal_to<int13, lazy<can_be_evaluated_only_once>::type::the_result>
  >(MPLLIBS_HERE, "test_evaluation_limit");

  meta_require<
    equal_to<int13, lazy<lazy<can_be_evaluated_only_once> >::type::the_result>
  >(MPLLIBS_HERE, "test_evaluation_limit_of_double_lazy");
}


