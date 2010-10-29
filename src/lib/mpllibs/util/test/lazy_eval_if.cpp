// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/lazy_eval_if.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("lazy_eval_if");
  
  typedef
    mpllibs::util::lazy_eval_if<
      boost::mpl::equal_to<int13, int13>,
      boost::mpl::true_,
      boost::mpl::false_
    >
    EvaluatedCondition;
  
  typedef
    boost::mpl::eval_if<
      boost::mpl::false_,
      mpllibs::util::lazy_eval_if<can_not_be_instantiated, int11, int13>,
      boost::mpl::true_
    >
    NotEvaluatedCondition;

  typedef
    mpllibs::util::lazy_eval_if<
      boost::mpl::equal_to<int11, int13>,
      can_not_be_instantiated,
      boost::mpl::true_
    >
    NotEvaluatedTrueCase;

  typedef
    mpllibs::util::lazy_eval_if<
      boost::mpl::equal_to<int13, int13>,
      boost::mpl::true_,
      can_not_be_instantiated
    >
    NotEvaluatedFalseCase;
}

MPLLIBS_ADD_TEST(suite, EvaluatedCondition)
MPLLIBS_ADD_TEST(suite, NotEvaluatedCondition)
MPLLIBS_ADD_TEST(suite, NotEvaluatedTrueCase)
MPLLIBS_ADD_TEST(suite, NotEvaluatedFalseCase)




