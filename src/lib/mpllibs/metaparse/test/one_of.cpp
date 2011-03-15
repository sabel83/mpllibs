// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/one_char.h>
#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include <mpllibs/metaparse/util/define_data.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("one_of");
  
  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);
  
  typedef mpllibs::metaparse::fail<test_error> test_fail;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_0< >,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    Test0;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of_1<mpllibs::metaparse::one_char>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    Test1WithGood;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_1<test_fail>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    Test1WithBad;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of_2<
            mpllibs::metaparse::one_char,
            mpllibs::metaparse::one_char
          >,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    Test2WithTwoGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of_2<mpllibs::metaparse::one_char, test_fail>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    Test2WithFirstGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of_2<test_fail, mpllibs::metaparse::one_char>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    Test2WithSecondGood;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_2<test_fail, test_fail>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    Test2WithTwoBad;





  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_of< >,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    Test;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of<mpllibs::metaparse::one_char>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestWithGood;
  
  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<test_fail>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestWithBad;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of<
            mpllibs::metaparse::one_char,
            mpllibs::metaparse::one_char
          >,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestWithTwoGood;
    
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of<mpllibs::metaparse::one_char, test_fail>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestWithFirstGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_of<test_fail, mpllibs::metaparse::one_char>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestWithSecondGood;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<test_fail, test_fail>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestWithTwoBad;
}

MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test1WithGood)
MPLLIBS_ADD_TEST(suite, Test1WithBad)
MPLLIBS_ADD_TEST(suite, Test2WithTwoGood)
MPLLIBS_ADD_TEST(suite, Test2WithFirstGood)
MPLLIBS_ADD_TEST(suite, Test2WithSecondGood)
MPLLIBS_ADD_TEST(suite, Test2WithTwoBad)

MPLLIBS_ADD_TEST(suite, Test)
MPLLIBS_ADD_TEST(suite, TestWithGood)
MPLLIBS_ADD_TEST(suite, TestWithBad)
MPLLIBS_ADD_TEST(suite, TestWithTwoGood)
MPLLIBS_ADD_TEST(suite, TestWithFirstGood)
MPLLIBS_ADD_TEST(suite, TestWithSecondGood)
MPLLIBS_ADD_TEST(suite, TestWithTwoBad)


