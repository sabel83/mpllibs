// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keyword.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("keyword");

  typedef boost::mpl::list_c<
    char,
    'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
  > str_hello_world;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'x'> str_hellx;
  typedef boost::mpl::list_c<char, 'h', 'x', 'l', 'l', 'o'> str_hxllo;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::keyword<str_hello, char_l>,
        str_hello
      >::type::first,
      char_l
    >
    TestResultType;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::keyword<str_hello>, str_>::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::keyword<str_hello>,
        str_hello
      >::type::second,
      str_
    >
    TestItself;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::keyword<str_hello>,
        str_hello_world
      >::type::second,
      boost::mpl::list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
    TestMoreThanItself;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::keyword<str_hello>,
        str_hellx
      >::type,
      mpllibs::parser::nothing
    >
    TestNonMatchAtEnd;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::keyword<str_hello>, str_hxllo>::type,
      mpllibs::parser::nothing
    >
    TestNonMatchInTheMiddle;
}

MPLLIBS_ADD_TEST(suite, TestResultType)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, TestItself)
MPLLIBS_ADD_TEST(suite, TestMoreThanItself)
MPLLIBS_ADD_TEST(suite, TestNonMatchAtEnd)
MPLLIBS_ADD_TEST(suite, TestNonMatchInTheMiddle)


