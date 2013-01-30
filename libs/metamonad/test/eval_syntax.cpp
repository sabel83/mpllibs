// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_eval_syntax)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::returns;

  using boost::mpl::equal_to;
  using boost::mpl::plus;

  meta_require<
    equal_to<int13, eval_syntax<syntax<plus<int11, int2> > >::type>
  >(MPLLIBS_HERE, "test_evaluating_a_syntax");

  meta_require<
    equal_to<int13, eval_syntax<returns<syntax<plus<int11, int2> > > >::type>
  >(MPLLIBS_HERE, "test_laziness_of_eval_syntax");
}


