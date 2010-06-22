// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/token.h>
#include <mpllibs/parser/keyword.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o', ' ', '\t'>
    str_hello_t;
      
  typedef mpllibs::parser::keyword<str_hello, int13> testParser;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::token<testParser>::apply<str_hello>::type::first,
      testParser::apply<str_hello>::type::first
    >
    Token_TestNoSpace;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::token<testParser>::apply<str_hello_t>::type::first,
      testParser::apply<str_hello>::type::first
    >
    Token_TestSpaces;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::token<testParser>::apply<str_hello_t>::type::second,
      str_
    >
    Token_TestSpacesConsumed;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::token<testParser>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Token_TestFail;
}

MPLLIBS_ADD_TEST(Token_TestNoSpace)
MPLLIBS_ADD_TEST(Token_TestSpaces)
MPLLIBS_ADD_TEST(Token_TestSpacesConsumed)
MPLLIBS_ADD_TEST(Token_TestFail)


