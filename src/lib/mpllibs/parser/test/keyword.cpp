// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keyword.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<
    char,
    'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
  > str_hello_world;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'x'> str_hellx;
  typedef boost::mpl::list_c<char, 'h', 'x', 'l', 'l', 'o'> str_hxllo;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<
        str_hello,
        char_l
      >::apply<str_hello>::type::first,
      char_l
    >
    Keyword_TestResultType;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<str_hello>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Keyword_TestEmptyInput;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::keyword<str_hello>::apply<str_hello>::type::second,
      str_
    >
    Keyword_TestItself;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::keyword<str_hello>::apply<str_hello_world>::type::second,
      boost::mpl::list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
    Keyword_TestMoreThanItself;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<str_hello>::apply<str_hellx>::type,
      mpllibs::parser::nothing
    >
    Keyword_TestNonMatchAtEnd;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<str_hello>::apply<str_hxllo>::type,
      mpllibs::parser::nothing
    >
    Keyword_TestNonMatchInTheMiddle;
}

MPLLIBS_ADD_TEST(Keyword_TestResultType)
MPLLIBS_ADD_TEST(Keyword_TestEmptyInput)
MPLLIBS_ADD_TEST(Keyword_TestItself)
MPLLIBS_ADD_TEST(Keyword_TestMoreThanItself)
MPLLIBS_ADD_TEST(Keyword_TestNonMatchAtEnd)
MPLLIBS_ADD_TEST(Keyword_TestNonMatchInTheMiddle)


