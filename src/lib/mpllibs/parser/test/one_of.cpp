// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/fail.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_0< >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    OneOf_Test0;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_1<
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_Test1WithGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_1<
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    OneOf_Test1WithBad;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::one_char,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_Test2WithTwoGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::one_char,
        mpllibs::parser::fail
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_Test2WithFirstGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::fail,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_Test2WithSecondGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of_2<
        mpllibs::parser::fail,
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    OneOf_Test2WithTwoBad;





  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of< >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    OneOf_Test;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_TestWithGood;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    OneOf_TestWithBad;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_TestWithTwoGood;
    
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char,
        mpllibs::parser::fail
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_TestWithFirstGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::fail,
        mpllibs::parser::one_char
      >::apply<str_hello>::type::first,
      char_h
    >
    OneOf_TestWithSecondGood;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_of<
        mpllibs::parser::fail,
        mpllibs::parser::fail
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    OneOf_TestWithTwoBad;
}

MPLLIBS_ADD_TEST(OneOf_Test0)
MPLLIBS_ADD_TEST(OneOf_Test1WithGood)
MPLLIBS_ADD_TEST(OneOf_Test1WithBad)
MPLLIBS_ADD_TEST(OneOf_Test2WithTwoGood)
MPLLIBS_ADD_TEST(OneOf_Test2WithFirstGood)
MPLLIBS_ADD_TEST(OneOf_Test2WithSecondGood)
MPLLIBS_ADD_TEST(OneOf_Test2WithTwoBad)

MPLLIBS_ADD_TEST(OneOf_Test)
MPLLIBS_ADD_TEST(OneOf_TestWithGood)
MPLLIBS_ADD_TEST(OneOf_TestWithBad)
MPLLIBS_ADD_TEST(OneOf_TestWithTwoGood)
MPLLIBS_ADD_TEST(OneOf_TestWithFirstGood)
MPLLIBS_ADD_TEST(OneOf_TestWithSecondGood)
MPLLIBS_ADD_TEST(OneOf_TestWithTwoBad)


