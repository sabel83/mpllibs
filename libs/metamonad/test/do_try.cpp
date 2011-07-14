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

#include <boost/type_traits/is_same.hpp>

#include "common.hpp"

using boost::mpl::equal_to;
using boost::mpl::identity;
using boost::mpl::tag;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::exception;
using mpllibs::metamonad::catch_any;

namespace
{
  const suite_path suite("do_try");
  
  MPLLIBS_DEFINE_TAG(tag1)
  MPLLIBS_DEFINE_META_ATOM(tag1, e1)
  
  MPLLIBS_DEFINE_TAG(tag2)
  MPLLIBS_DEFINE_META_ATOM(tag2, e2)

  typedef
    equal_to<
      int13,
      MPLLIBS_DO_TRY<
        MPLLIBS_RETURN<int13>
      >
      ::catch_<tag1, x>
        ::apply<int11>
      ::type
    >
    test_no_exception;

  typedef
    equal_to<
      int11,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<e1>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_catch;

  typedef
    equal_to<
      int13,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<int13>
      >
      ::catch_<tag<int13>::type, x>
        ::apply<identity<x> >
      ::type
    >
    test_exception_value_in_catch;

  typedef
    equal_to<
      exception<int13>,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<int13>
      >
      ::catch_<tag2, x>
        ::apply<identity<int11> >
      ::type
    >
    test_not_catching;

  typedef
    equal_to<
      int13,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<e2>
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
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<e1>,
        MPLLIBS_RETURN<int1>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_exception_propagation;


  typedef
    equal_to<
      int11,
      MPLLIBS_DO_TRY<
        MPLLIBS_RETURN<int13>,
        MPLLIBS_RETURN<int11>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_execution_sequence;
  
  typedef
    equal_to<
      int11,
      MPLLIBS_DO_TRY<
        MPLLIBS_SET<x, MPLLIBS_THROW<e1> >,
        MPLLIBS_RETURN<int1>
      >
      ::catch_<tag1, x>
        ::apply<identity<int11> >
      ::type
    >
    test_exception_in_set;

  typedef
    equal_to<
      int13,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<e1>,
        MPLLIBS_RETURN<int1>
      >
      ::catch_<catch_any, x>
        ::apply<identity<int13> >
      ::type
    >
    test_catch_any;

  typedef
    equal_to<
      exception<int13>,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<e1>,
        MPLLIBS_RETURN<int1>
      >
      ::catch_<catch_any, x>
        ::apply<MPLLIBS_THROW<int13> >
      ::type
    >
    test_rethrowing;

  typedef
    equal_to<
      exception<int13>,
      MPLLIBS_DO_TRY<
        MPLLIBS_THROW<e1>,
        MPLLIBS_RETURN<int1>
      >
      ::catch_<catch_any, x>
        ::apply<MPLLIBS_THROW<int13> >
      ::catch_<catch_any, x>
        ::apply<MPLLIBS_THROW<int13> >
      ::type
    >
    test_rethrowing_not_caught_by_next_catch;
}

MPLLIBS_ADD_TEST(suite, test_no_exception)
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


