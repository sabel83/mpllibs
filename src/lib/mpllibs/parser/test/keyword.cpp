// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keyword.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_equal_sequence.h>
#include <mpllibs/test/test_equal.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>

namespace
{
  typedef boost::mpl::integral_c<char, 'h'> hCharacter;
  typedef boost::mpl::integral_c<char, 'e'> eCharacter;
  typedef boost::mpl::integral_c<char, 'l'> lCharacter;
      
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<
    char,
    'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
  > helloWorldString;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'x'> hellxString;
  typedef boost::mpl::list_c<char, 'h', 'x', 'l', 'l', 'o'> hxlloString;
  typedef boost::mpl::list_c<char> emptyString;

  struct TestResultType :
    mpllibs::test::test_equal<
      mpllibs::parser::keyword<
        helloString,
        lCharacter
      >::apply<helloString>::type::first,
      lCharacter
    >
  {};

  struct TestEmptyInput :
    mpllibs::test::test_equal<
      mpllibs::parser::keyword<helloString>::apply<emptyString>::type,
      mpllibs::parser::nothing
    >
  {};

  struct TestItself :
    mpllibs::test::test_equal_sequence<
      mpllibs::parser::keyword<helloString>::apply<helloString>::type::second,
      boost::mpl::list_c<char>
    >
  {};
      
  struct TestMoreThanItself :
    mpllibs::test::test_equal_sequence<
      mpllibs::parser::keyword<helloString>::apply<
        helloWorldString
      >::type::second,
      boost::mpl::list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
  {};

  struct TestNonMatchAtEnd :
    mpllibs::test::test_equal<
      mpllibs::parser::keyword<helloString>::apply<hellxString>::type,
      mpllibs::parser::nothing
    >
  {};
      
  struct TestNonMatchInTheMiddle :
    mpllibs::test::test_equal<
      mpllibs::parser::keyword<helloString>::apply<hxlloString>::type,
      mpllibs::parser::nothing
    >
  {};
}

