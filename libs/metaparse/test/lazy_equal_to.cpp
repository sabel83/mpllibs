// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/lazy_equal_to.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_lazy_equal_to)
{
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::util::lazy_equal_to;
  
  using boost::mpl::eval_if;
  using boost::mpl::false_;
  using boost::mpl::true_;

  meta_require<lazy_equal_to<int13, int13> >(MPLLIBS_HERE, "test_evaluated");
  
  meta_require<
    eval_if<false_, lazy_equal_to<can_not_be_instantiated, int13>, true_>
  >(MPLLIBS_HERE, "test_not_evaluated");
}


