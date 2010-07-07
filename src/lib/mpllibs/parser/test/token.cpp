// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/token.h>
#include <mpllibs/parser/keyword.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("token");

  typedef
    boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o', ' ', '\t'>
    str_hello_t;
      
  typedef mpllibs::parser::keyword<str_hello, int13> testParser;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::token<testParser>,
        str_hello
      >::type::first,
      boost::mpl::apply<testParser, str_hello>::type::first
    >
    TestNoSpace;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::token<testParser>,
        str_hello_t
      >::type::first,
      boost::mpl::apply<testParser, str_hello>::type::first
    >
    TestSpaces;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::token<testParser>,
        str_hello_t
      >::type::second,
      str_
    >
    TestSpacesConsumed;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::token<testParser>, str_>::type,
      mpllibs::parser::nothing
    >
    TestFail;
}

MPLLIBS_ADD_TEST(suite, TestNoSpace)
MPLLIBS_ADD_TEST(suite, TestSpaces)
MPLLIBS_ADD_TEST(suite, TestSpacesConsumed)
MPLLIBS_ADD_TEST(suite, TestFail)


