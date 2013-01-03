// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/eval_case.hpp>

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

  using boost::is_same;

  meta_require<
    equal_to<
      int13,
      let<
        x, int13,
        x
      >::type
    >
  >(MPLLIBS_HERE, "test_let_name");

  meta_require<
    equal_to<
      int11,
      let<
        x, int13,
        int11
      >::type
    >
  >(MPLLIBS_HERE, "test_let_not_name");
  
  meta_require<
    equal_to<
      int26,
      let<
        x, int13,
        double_value<x>
      >::type
    >
  >(MPLLIBS_HERE, "test_template");

  meta_require<
    equal_to<
      int24,
      let<
        x, int13,
        let<
          y, int11,
          plus<x, y>
        >::type
      >::type::type
    >
  >(MPLLIBS_HERE, "test_nested_let");
  
  meta_require<
    equal_to<
      int37,
      let<
        x, int13,
        double_lazy_plus<
          x,
          let<
            x, int11,
            plus<x, int13>
          >
        >
      >::type::type
    >
  >(MPLLIBS_HERE, "test_shadowing");

  meta_require<
    is_same<int, let<x, double, int>::type>
  >(MPLLIBS_HERE, "test_let_not_evaluating_its_body");

  meta_require<
    is_same<
      eval_case< int,
        matches<int, some_template<int, double> >
      >,
      let<
        x, double,
        eval_case< int,
          matches<int, some_template<int, x> >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_case_in_multi_let");

  meta_require<
    equal<list<int, double>, let<x, int, list<x, double> >::type>
  >(MPLLIBS_HERE, "test_list_in_let");
}



