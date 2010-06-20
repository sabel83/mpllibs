// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keyword.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/equal_to.hpp>

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

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<
        helloString,
        lCharacter
      >::apply<helloString>::type::first,
      lCharacter
    >::type
    Keyword_TestResultType;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<helloString>::apply<emptyString>::type,
      mpllibs::parser::nothing
    >::type
    Keyword_TestEmptyInput;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::keyword<helloString>::apply<helloString>::type::second,
      boost::mpl::list_c<char>
    >::type
    Keyword_TestItself;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::keyword<helloString>::apply<
        helloWorldString
      >::type::second,
      boost::mpl::list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >::type
    Keyword_TestMoreThanItself;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<helloString>::apply<hellxString>::type,
      mpllibs::parser::nothing
    >::type
    Keyword_TestNonMatchAtEnd;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keyword<helloString>::apply<hxlloString>::type,
      mpllibs::parser::nothing
    >::type
    Keyword_TestNonMatchInTheMiddle;
}

MPLLIBS_ADD_TEST(Keyword_TestResultType)
MPLLIBS_ADD_TEST(Keyword_TestEmptyInput)
MPLLIBS_ADD_TEST(Keyword_TestItself)
MPLLIBS_ADD_TEST(Keyword_TestMoreThanItself)
MPLLIBS_ADD_TEST(Keyword_TestNonMatchAtEnd)
MPLLIBS_ADD_TEST(Keyword_TestNonMatchInTheMiddle)


