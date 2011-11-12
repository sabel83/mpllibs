// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/lazy_eval_if.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal_to.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_util_lazy_eval_if)
{
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::util::lazy_eval_if;
  
  using boost::mpl::equal_to;
  using boost::mpl::true_;
  using boost::mpl::false_;
  using boost::mpl::eval_if;

  meta_require<
    lazy_eval_if<equal_to<int13, int13>, true_, false_>
  >(MPLLIBS_HERE, "evaluated_condition");
  
  meta_require<
    eval_if<false_, lazy_eval_if<can_not_be_instantiated, int11, int13>, true_>
  >(MPLLIBS_HERE, "not_evaluated_condition");

  meta_require<
    lazy_eval_if<equal_to<int11, int13>, can_not_be_instantiated, true_>
  >(MPLLIBS_HERE, "not_evaluated_true_case");

  meta_require<
    lazy_eval_if<equal_to<int13, int13>, true_, can_not_be_instantiated>
  >(MPLLIBS_HERE, "not_evaluated_false_case");
}



