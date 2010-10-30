// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/one_char.h>
#include <mpllibs/metaparse/fail.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("one_of");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::one_of_0< >, str_hello>::type,
      mpllibs::metaparse::nothing
    >
    Test0;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_1<mpllibs::metaparse::one_char>,
        str_hello
      >::type::first,
      char_h
    >
    Test1WithGood;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_1<mpllibs::metaparse::fail>,
        str_hello
      >::type,
      mpllibs::metaparse::nothing
    >
    Test1WithBad;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_2<
          mpllibs::metaparse::one_char,
          mpllibs::metaparse::one_char
        >,
        str_hello
      >::type::first,
      char_h
    >
    Test2WithTwoGood;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_2<
          mpllibs::metaparse::one_char,
          mpllibs::metaparse::fail
        >,
        str_hello
      >::type::first,
      char_h
    >
    Test2WithFirstGood;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_2<
          mpllibs::metaparse::fail,
          mpllibs::metaparse::one_char
        >,
        str_hello
      >::type::first,
      char_h
    >
    Test2WithSecondGood;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of_2<
          mpllibs::metaparse::fail,
          mpllibs::metaparse::fail
        >,
        str_hello
      >::type,
      mpllibs::metaparse::nothing
    >
    Test2WithTwoBad;





  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::one_of< >, str_hello>::type,
      mpllibs::metaparse::nothing
    >
    Test;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<mpllibs::metaparse::one_char>,
        str_hello
      >::type::first,
      char_h
    >
    TestWithGood;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<mpllibs::metaparse::fail>,
        str_hello
      >::type,
      mpllibs::metaparse::nothing
    >
    TestWithBad;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::one_char,
          mpllibs::metaparse::one_char
        >,
        str_hello
      >::type::first,
      char_h
    >
    TestWithTwoGood;
    
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::one_char,
          mpllibs::metaparse::fail
        >,
        str_hello
      >::type::first,
      char_h
    >
    TestWithFirstGood;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::fail,
          mpllibs::metaparse::one_char
        >,
        str_hello
      >::type::first,
      char_h
    >
    TestWithSecondGood;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::fail,
          mpllibs::metaparse::fail
        >,
        str_hello
      >::type,
      mpllibs::metaparse::nothing
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


