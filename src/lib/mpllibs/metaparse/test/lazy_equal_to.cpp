// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/lazy_equal_to.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::lazy_equal_to;

using boost::mpl::eval_if;
using boost::mpl::false_;
using boost::mpl::true_;

namespace
{
  const suite_path suite = suite_path("util")("lazy_equal_to");
  
  typedef lazy_equal_to<int13, int13> test_evaluated;
  
  typedef
    eval_if<false_, lazy_equal_to<can_not_be_instantiated, int13>, true_>
    test_not_evaluated;
}

MPLLIBS_ADD_TEST(suite, test_evaluated)
MPLLIBS_ADD_TEST(suite, test_not_evaluated)



