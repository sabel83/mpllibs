// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/let_c.hpp>
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

BOOST_AUTO_TEST_CASE(test_let_c)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::equal;
  using boost::mpl::equal_to;
  using boost::mpl::plus;
  using boost::mpl::list;
  
  using mpllibs::metamonad::let_c;
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::matches_c;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::eval_syntax;
  using mpllibs::metamonad::eval_guard;

  using boost::is_same;

  meta_require<
    equal_to<int13, eval_syntax<let_c<x, int13, x> >::type>
  >(MPLLIBS_HERE, "test_let_name");

  meta_require<
    equal_to<int11, eval_syntax<let_c<x, int13, int11> >::type>
  >(MPLLIBS_HERE, "test_let_not_name");
  
  meta_require<
    equal_to<
      int26,
      eval_syntax<let_c<x, int13, double_value<x> > >::type
    >
  >(MPLLIBS_HERE, "test_template");

  meta_require<
    equal_to<
      int24,
      eval_syntax<
        let_c<x, int13, eval_syntax<let_c<y, int11, plus<x, y> > > >
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_let");
  
  meta_require<
    equal_to<
      int37,
      eval_syntax<
        let_c<
          x, int13,
          double_lazy_plus<x, eval_syntax<let_c<x, int11, plus<x, int13> > > >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_shadowing");

  meta_require<
    is_same<syntax<int>, let_c<x, double, int>::type>
  >(MPLLIBS_HERE, "test_let_not_evaluating_its_body");

  meta_require<
    is_same<
      syntax<eval_case<int, matches_c<int, some_template<int, double> > > >,
      let_c<
        x, double,
        eval_case<int, matches_c<int, some_template<int, x> > >
      >::type
    >
  >(MPLLIBS_HERE, "test_case_in_multi_let");

  meta_require<
    equal<
      list<int, double>,
      eval_syntax<let_c<x, int, list<x, double> > >::type
    >
  >(MPLLIBS_HERE, "test_list_in_let");

  meta_require<
    is_same<syntax<eval_guard<int13> >, let_c<x, int13, eval_guard<x> >::type>
  >(MPLLIBS_HERE, "test_let_c_and_eval_guard");

  meta_require<
    is_same<
      syntax<let_c<y, int11, some_template<int13, y> > >,
      let_c<x, int13, let_c<y, int11, some_template<x, y> > >::type
    >
  >(MPLLIBS_HERE, "test_let_c_and_eval_guard");
}



