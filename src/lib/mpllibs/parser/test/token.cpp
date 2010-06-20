// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/token.h>
#include <mpllibs/parser/keyword.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::integral_c<char, 'h'> hCharacter;
  typedef boost::mpl::integral_c<char, 'e'> eCharacter;
  typedef boost::mpl::integral_c<char, 'l'> lCharacter;
      
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef
    boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o', ' ', '\t'>
    helloSpaceString;
  typedef boost::mpl::list_c<char> emptyString;
      
  typedef
    mpllibs::parser::keyword<helloString, boost::mpl::int_<13> >
    testParser;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::token<testParser>::apply<helloString>::type::first,
      testParser::apply<helloString>::type::first
    >::type
    Token_TestNoSpace;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::token<testParser>::apply<helloSpaceString>::type::first,
      testParser::apply<helloString>::type::first
    >::type
    Token_TestSpaces;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::token<testParser>::apply<helloSpaceString>::type::second,
      boost::mpl::list_c<char>
    >::type
    Token_TestSpacesConsumed;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::token<testParser>::apply<emptyString>::type,
      mpllibs::parser::nothing
    >::type
    Token_TestFail;
}

MPLLIBS_ADD_TEST(Token_TestNoSpace)
MPLLIBS_ADD_TEST(Token_TestSpaces)
MPLLIBS_ADD_TEST(Token_TestSpacesConsumed)
MPLLIBS_ADD_TEST(Token_TestFail)


