// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/lazy_equal_to.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("lazy_equal_to");
  
  typedef boost::mpl::int_<13> int13;
  typedef boost::mpl::int_<11> int11;
  
  typedef mpllibs::util::lazy_equal_to<int13, int13> Evaluated;
  
  typedef
    boost::mpl::eval_if<
      boost::mpl::false_,
      mpllibs::util::lazy_equal_to<
        boost::mpl::at<boost::mpl::vector<int, double>, int11>,
        int13
      >,
      boost::mpl::true_
    >
    NotEvaluated;
}

MPLLIBS_ADD_TEST(suite, Evaluated)
MPLLIBS_ADD_TEST(suite, NotEvaluated)

