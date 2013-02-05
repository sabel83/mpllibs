// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/case.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/let_c.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>

#include "common.hpp"

using mpllibs::metamonad::tmp_value;

namespace
{
  template <class A, class B>
  struct some_template : tmp_value<some_template<A, B> > {};

  template <class A, class B>
  struct some_other_template : tmp_value<some_other_template<A, B> > {};
}

BOOST_AUTO_TEST_CASE(test_case)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::case_;
  using mpllibs::metamonad::matches;
  using mpllibs::metamonad::matches_c;
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::no_case_matched;
  using mpllibs::metamonad::var;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::box;
  using mpllibs::metamonad::let_c;

  using boost::is_same;

  using boost::mpl::equal_to;

  meta_require<
    is_same<
      exception<no_case_matched<box<int> > >,
      case_< box<int>,
        matches<syntax<box<double> >, syntax<float> >
      >::type
    >
  >(MPLLIBS_HERE, "test_no_matches");

  meta_require<
    is_same<
      syntax<float>,
      case_< box<int>,
        matches<syntax<box<int> >, syntax<float> >
      >::type
    >
  >(MPLLIBS_HERE, "test_match");

  meta_require<
    is_same<
      syntax<float>,
      case_< box<int>,
        matches<syntax<box<int> >, syntax<float> >,
        matches<syntax<box<double> >, syntax<char> >
      >::type
    >
  >(MPLLIBS_HERE, "test_first_matches");

  meta_require<
    is_same<
      syntax<float>,
      case_< box<int>,
        matches<syntax<box<double> >, syntax<char> >,
        matches<syntax<box<int> >, syntax<float> >
      >::type
    >
  >(MPLLIBS_HERE, "test_second_matches");

  meta_require<
    is_same<
      syntax<some_other_template<int, double> >,
      case_< some_template<int, double>,
        matches<syntax<some_template<x, y> >,
          syntax<some_other_template<x, y> >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_vars_in_pattern");

  meta_require<
    is_same<
      syntax<case_< int2, matches_c<y, boost::mpl::plus<int11, y> > > >,
      case_< int11,
        matches<syntax<x>,
          syntax<
            case_<int2,
              matches_c<y, boost::mpl::plus<x, y> >
            >
          >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_case");

  meta_require<
    is_same<
      syntax<matches_c<some_template<int11, int13>, int11> >,
      let_c<x, int11, matches_c<some_template<x, int13>, x> >::type
    >
  >(MPLLIBS_HERE, "test_matches_in_let");
}


