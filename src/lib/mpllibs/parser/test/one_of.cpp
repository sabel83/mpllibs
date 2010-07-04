// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/fail.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("one_of");

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_0< >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Test0;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_1<
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    Test1WithGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_1<
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Test1WithBad;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::one_char,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    Test2WithTwoGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::one_char,
        mpllibs::parser::fail
      >::apply<str_hello>::type::first,
      char_h
    >
    Test2WithFirstGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::fail,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    Test2WithSecondGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::fail,
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Test2WithTwoBad;





  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of< >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Test;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    TestWithGood;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    TestWithBad;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    TestWithTwoGood;
    
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char,
        mpllibs::parser::fail
      >::apply<str_hello>::type::first,
      char_h
    >
    TestWithFirstGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::fail,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    TestWithSecondGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::fail,
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
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


