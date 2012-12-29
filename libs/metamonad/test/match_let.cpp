// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/match_let.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

namespace
{
  template <class A, class B>
  struct some_template;

  template <class A, class B>
  struct some_other_template;
}

BOOST_AUTO_TEST_CASE(test_match_let)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::match_let;
  using mpllibs::metamonad::var;
  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::returns;

  using boost::is_same;

  using namespace mpllibs::metamonad::name;

  meta_require<
    is_same<int, match_let<var<x>, returns<int>, x>::type>
  >(MPLLIBS_HERE, "test_setting_value");

  meta_require<
    is_same<x, match_let<int, returns<int>, x>::type>
  >(MPLLIBS_HERE, "test_nothing_to_set");

  meta_require<
    is_same<
      some_other_template<int, double>,
      match_let<
        some_template<var<x>, var<y> >, returns<some_template<int, double> >,
        some_other_template<x, y>
      >::type
    >
  >(MPLLIBS_HERE, "test_multiple_variables");

  meta_require<
    is_same<
      eval_case< returns<int>,
        matches<int, some_template<double, int> >
      >,
      match_let<
        var<x>, returns<double>,
        eval_case< returns<int>,
          matches<int, some_template<x, int> >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_case_in_match_let");
}


