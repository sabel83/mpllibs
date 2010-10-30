// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/lazy_equal_to.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::lazy_equal_to");
  
  typedef mpllibs::metaparse::util::lazy_equal_to<int13, int13> Evaluated;
  
  typedef
    boost::mpl::eval_if<
      boost::mpl::false_,
      mpllibs::metaparse::util::lazy_equal_to<can_not_be_instantiated, int13>,
      boost::mpl::true_
    >
    NotEvaluated;
}

MPLLIBS_ADD_TEST(suite, Evaluated)
MPLLIBS_ADD_TEST(suite, NotEvaluated)



