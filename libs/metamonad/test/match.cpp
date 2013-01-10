// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/match.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/is_exception.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/insert.hpp>

#include "common.hpp"

using boost::mpl::equal_to;
using boost::mpl::begin;
using boost::mpl::end;
using boost::mpl::distance;
using boost::mpl::not_;
using boost::mpl::and_;
using boost::mpl::equal;
using boost::mpl::map;
using boost::mpl::pair;
using boost::mpl::fold;
using boost::mpl::true_;
using boost::mpl::first;
using boost::mpl::second;
using boost::mpl::at;
using boost::mpl::size;

using boost::is_same;

using mpllibs::metamonad::is_exception;
using mpllibs::metamonad::lambda;
using mpllibs::metamonad::lazy;
using mpllibs::metamonad::already_lazy;

using namespace mpllibs::metamonad::name;

namespace
{
  MPLLIBS_METAFUNCTION(is_empty, (S))
  ((
    and_<
      typename not_<typename is_exception<S>::type>::type,
      typename equal_to<
        int0,
        typename distance<typename begin<S>::type, typename end<S>::type>::type
      >::type
    >
  ));

  MPLLIBS_METAFUNCTION(same_map_cb, (B))
  ((
    lambda<s, p,
      lazy<
        and_<
          already_lazy<s>,
          is_same<
            at<already_lazy<B>, first<already_lazy<p> > >,
            second<already_lazy<p> >
          >
        >
      >
    >
  ));

  // equal depends on the order of elements in the map
  MPLLIBS_METAFUNCTION(same_map, (A)(B))
  ((
    and_<
      typename fold<A, true_, same_map_cb<B> >::type,
      typename equal_to<typename size<A>::type, typename size<B>::type>::type
    >
  ));

  MPLLIBS_METAFUNCTION(not_same_map, (A)(B))
  ((not_<typename same_map<A, B>::type>));

  template <class A, class B, class C>
  struct some_template;
}

BOOST_AUTO_TEST_CASE(test_match)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::match;
  using mpllibs::metamonad::_;
  using mpllibs::metamonad::var;
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::bad_match;

  using boost::mpl::equal;
  using boost::mpl::insert;
  using boost::mpl::na;

  // same_map

  meta_require<
    not_same_map<
      map<pair<int, double>, pair<char, float> >,
      map<pair<char, float>, pair<double, double> >
    >
  >(MPLLIBS_HERE, "test_different_map");

  meta_require<
    not_same_map<
      map<pair<int, double>, pair<char, float> >,
      map<pair<char, float> >
    >
  >(MPLLIBS_HERE, "test_smaller_map");

  meta_require<
    not_same_map<
      map<pair<int, double> >,
      map<pair<char, float>, pair<int, double> >
    >
  >(MPLLIBS_HERE, "test_bigger_map");

  meta_require<
    same_map<
      map<pair<int, double>, pair<char, float> >,
      map<pair<char, float>, pair<int, double> >
    >
  >(MPLLIBS_HERE, "test_same_map");

  meta_require<
    same_map<map<pair<int, double> >, insert<map<>, pair<int, double> >::type>
  >(MPLLIBS_HERE, "test_same_map_after_insert");

  // match

  meta_require<is_empty<match<_, int> > >(MPLLIBS_HERE, "test_match_any");

  meta_require<
    is_same<
      exception<bad_match<double, int> >,
      match<double, int>::type
    >
  >(MPLLIBS_HERE, "test_no_match");

  meta_require<
    is_empty<match<int, int> >
  >(MPLLIBS_HERE, "test_match_same_type");

  meta_require<
    same_map<map<pair<x, int13> >, match<x, int13>::type>
  >(MPLLIBS_HERE, "test_match_var");

  meta_require<
    is_empty<
      match<some_template<_, int, double>, some_template<char, int, double> >
    >
  >(MPLLIBS_HERE, "test_nested_match_any");

  meta_require<
    is_same<
      exception<bad_match<int, char> >,
      match<
        some_template<int, int, double>,
        some_template<char, int, double>
      >::type
    >
  >(MPLLIBS_HERE, "test_bad_nested_match");

  meta_require<
    same_map<
      map<pair<x, int13> >,
      match<
        some_template<int, double, x>,
        some_template<int, double, int13>
      >::type
    >
  >(MPLLIBS_HERE, "test_match_nested_var");

  meta_require<
    same_map<
      map<pair<x, int13> >,
      match<
        some_template<x, double, x>,
        some_template<int13, double, int13>
      >::type
    >
  >(MPLLIBS_HERE, "test_match_nested_var_twice");

  meta_require<
    is_same<
      exception<bad_match<x, double> >,
      match<
        some_template<x, int, x>,
        some_template<char, int, double>
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_var_twice_doesnt_match");

  meta_require<
    same_map<
      map<pair<x, int13>, pair<y, int11> >,
      match<
        some_template<y, double, x>,
        some_template<int11, double, int13>
      >::type
    >
  >(MPLLIBS_HERE, "test_two_vars");

  meta_require<
    same_map<
      map<pair<x, na> >,
      match<some_template<x, _, _>, some_template<na, na, na> >::type
    >
  >(MPLLIBS_HERE, "test_match_with_na_template_argument");
}


