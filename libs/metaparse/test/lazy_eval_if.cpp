// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/lazy_eval_if.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::util::lazy_eval_if;

using boost::mpl::equal_to;
using boost::mpl::true_;
using boost::mpl::false_;
using boost::mpl::eval_if;

namespace
{
  const suite_path suite = suite_path("util")("lazy_eval_if");
  
  typedef
    has_type<lazy_eval_if<equal_to<int13, int13>, true_, false_> >
    test_has_type;

  typedef
    lazy_eval_if<equal_to<int13, int13>, true_, false_>
    test_evaluated_condition;
  
  typedef
    eval_if<false_, lazy_eval_if<can_not_be_instantiated, int11, int13>, true_>
    test_not_evaluated_condition;

  typedef
    lazy_eval_if<equal_to<int11, int13>, can_not_be_instantiated, true_>
    test_not_evaluated_true_case;

  typedef
    lazy_eval_if<equal_to<int13, int13>, true_, can_not_be_instantiated>
    test_not_evaluated_false_case;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_evaluated_condition)
MPLLIBS_ADD_TEST(suite, test_not_evaluated_condition)
MPLLIBS_ADD_TEST(suite, test_not_evaluated_true_case)
MPLLIBS_ADD_TEST(suite, test_not_evaluated_false_case)




