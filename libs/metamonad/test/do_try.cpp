// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/do_try.hpp>
#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/plus.hpp>

#include <boost/type_traits/is_same.hpp>

#include "common.hpp"

using boost::mpl::equal_to;
using boost::mpl::identity;
using boost::mpl::tag;
using boost::mpl::plus;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::exception;
using mpllibs::metamonad::catch_any;
using mpllibs::metamonad::do_try;
using mpllibs::metamonad::throw_;
using mpllibs::metamonad::set;
using mpllibs::metamonad::do_return;

namespace
{
  const suite_path suite("do_try");
  
  MPLLIBS_DEFINE_TAG(tag1)
  MPLLIBS_DEFINE_META_ATOM(tag1, e1)
  
  MPLLIBS_DEFINE_TAG(tag2)
  MPLLIBS_DEFINE_META_ATOM(tag2, e2)
  
  struct t1;
  struct t2;

  typedef
    equal_to<
      int13,
      do_try<
        do_return<int13>
      >
      ::catch_<tag1, x>
        ::apply<int11>
      ::type
    >
    test_no_exception;

  typedef
    equal_to<
      int2,
      do_try<
        set<t1, int1>,
        set<t2, int1>,
        plus<t1, t2>
      >::type
    >
    test_no_exception_no_catch;

  typedef
    equal_to<
      int11,
      do_try<
        throw_<e1>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_catch;

  typedef
    equal_to<
      int13,
      do_try<
        throw_<int13>
      >
      ::catch_<tag<int13>::type, x>
        ::apply<identity<x> >
      ::type
    >
    test_exception_value_in_catch;

  typedef
    equal_to<
      exception<int13>,
      do_try<
        throw_<int13>
      >
      ::catch_<tag2, x>
        ::apply<identity<int11> >
      ::type
    >
    test_not_catching;

  typedef
    equal_to<
      int13,
      do_try<
        throw_<e2>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::catch_<tag2, x>
        ::apply<identity<int13> >
      ::type
    >
    test_second_catch;

  typedef
    equal_to<
      int11,
      do_try<
        throw_<e1>,
        do_return<int1>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_exception_propagation;


  typedef
    equal_to<
      int11,
      do_try<
        do_return<int13>,
        do_return<int11>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_execution_sequence;
  
  typedef
    equal_to<
      int11,
      do_try<
        set<x, throw_<e1> >,
        do_return<int1>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_exception_in_set;

  typedef
    equal_to<
      int13,
      do_try<
        throw_<e1>,
        do_return<int1>
      >
      ::catch_<catch_any, x>
        ::apply<identity<int13> >
      ::type
    >
    test_catch_any;

  typedef
    equal_to<
      exception<int13>,
      do_try<
        throw_<e1>,
        do_return<int1>
      >
      ::catch_<catch_any, x>
        ::apply<throw_<int13> >
      ::type
    >
    test_rethrowing;

  typedef
    equal_to<
      exception<int13>,
      do_try<
        throw_<e1>,
        do_return<int1>
      >
      ::catch_<catch_any, x>
        ::apply<throw_<int13> >
      ::catch_<catch_any, x>
        ::apply<throw_<int13> >
      ::type
    >
    test_rethrowing_not_caught_by_next_catch;
}

MPLLIBS_ADD_TEST(suite, test_no_exception)
MPLLIBS_ADD_TEST(suite, test_no_exception_no_catch)
MPLLIBS_ADD_TEST(suite, test_catch)
MPLLIBS_ADD_TEST(suite, test_exception_value_in_catch)
MPLLIBS_ADD_TEST(suite, test_not_catching)
MPLLIBS_ADD_TEST(suite, test_second_catch)
MPLLIBS_ADD_TEST(suite, test_exception_propagation)
MPLLIBS_ADD_TEST(suite, test_execution_sequence)
MPLLIBS_ADD_TEST(suite, test_exception_in_set)
MPLLIBS_ADD_TEST(suite, test_catch_any)
MPLLIBS_ADD_TEST(suite, test_rethrowing)
MPLLIBS_ADD_TEST(suite, test_rethrowing_not_caught_by_next_catch)


