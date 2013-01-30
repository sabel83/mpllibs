// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/match_let_c.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/box.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

using mpllibs::metamonad::tmp_value;

namespace
{
  template <class A, class B>
  struct some_template : tmp_value<some_template<A, B> > {};

  template <class A, class B>
  struct some_other_template : tmp_value<some_other_template<A, B> > {};
}

BOOST_AUTO_TEST_CASE(test_match_let_c)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::match_let_c;
  using mpllibs::metamonad::var;
  using mpllibs::metamonad::eval_case;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::matches_c;
  using mpllibs::metamonad::returns;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::box;

  using boost::is_same;

  using namespace mpllibs::metamonad::name;

  meta_require<
    is_same<syntax<box<int> >, match_let_c<x, box<int>, x>::type>
  >(MPLLIBS_HERE, "test_setting_value");

  meta_require<
    is_same<syntax<x>, match_let_c<box<int>, returns<box<int> >, x>::type>
  >(MPLLIBS_HERE, "test_nothing_to_set");

  meta_require<
    is_same<
      syntax<some_other_template<int, double> >,
      match_let_c<
        some_template<x, y>,
        returns<some_template<int, double> >,
        some_other_template<x, y>
      >::type
    >
  >(MPLLIBS_HERE, "test_multiple_variables");

  meta_require<
    is_same<
      syntax<
        eval_case<returns<box<int> >,
          matches_c<box<int>, some_template<box<double>, int> >
        >
      >,
      match_let_c<
        x, returns<box<double> >,
        eval_case< returns<box<int> >,
          matches_c<box<int>, some_template<x, int> >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_case_in_match_let");
}


