// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/eval_guard.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

namespace
{
  template <class A, class B>
  struct some_template;
}

BOOST_AUTO_TEST_CASE(test_let)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::equal;
  using boost::mpl::equal_to;
  using boost::mpl::plus;
  using boost::mpl::list;
  
  using mpllibs::metamonad::let;
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::matches_c;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::eval_guard;

  using boost::is_same;

  meta_require<
    equal_to<int13, eval_syntax<let<x, syntax<int13>, syntax<x> > >::type>
  >(MPLLIBS_HERE, "test_let_name");

  meta_require<
    equal_to<int11, eval_syntax<let<x, syntax<int13>, syntax<int11> > >::type>
  >(MPLLIBS_HERE, "test_let_not_name");
  
  meta_require<
    equal_to<
      int26,
      eval_syntax<let<x, syntax<int13>, syntax<double_value<x> > > >::type
    >
  >(MPLLIBS_HERE, "test_template");

  meta_require<
    is_same<syntax<int>, let<x, syntax<double>, syntax<int> >::type>
  >(MPLLIBS_HERE, "test_let_not_evaluating_its_body");

  meta_require<
    is_same<
      syntax<eval_case<int, matches_c<int, some_template<int, double> > > >,
      let<
        x, syntax<double>,
        syntax<eval_case<int, matches_c<int, some_template<int, x> > > >
      >::type
    >
  >(MPLLIBS_HERE, "test_case_in_multi_let");

  meta_require<
    equal<
      list<int, double>,
      eval_syntax<let<x, syntax<int>, syntax<list<x, double> > > >::type
    >
  >(MPLLIBS_HERE, "test_list_in_let");

  meta_require<
    is_same<
      syntax<eval_guard<int13> >,
      let<x, syntax<int13>, syntax<eval_guard<x> > >::type
    >
  >(MPLLIBS_HERE, "test_let_and_eval_guard");
}



