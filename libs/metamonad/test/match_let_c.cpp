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

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/assert.hpp>

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

  // test_setting_value
  BOOST_MPL_ASSERT((
    is_same<syntax<box<int> >, match_let_c<x, box<int>, x>::type>
  ));

  // test_nothing_to_set
  BOOST_MPL_ASSERT((
    is_same<syntax<x>, match_let_c<box<int>, returns<box<int> >, x>::type>
  ));

  // test_multiple_variables
  BOOST_MPL_ASSERT((
    is_same<
      syntax<some_other_template<int, double> >,
      match_let_c<
        some_template<x, y>,
        returns<some_template<int, double> >,
        some_other_template<x, y>
      >::type
    >
  ));

  // test_case_in_match_let
  BOOST_MPL_ASSERT((
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
  ));
}


