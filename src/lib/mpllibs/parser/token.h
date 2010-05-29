#ifndef MPLLIBS_PARSER_TOKEN_H
#define MPLLIBS_PARSER_TOKEN_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/spaces.h>
#include <mpllibs/parser/first_of.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p>
    struct token : mpllibs::parser::first_of<p, mpllibs::parser::spaces> {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/keyword.h>

#include <mpllibs/test/test_equal.h>
#include <mpllibs/test/test_equal_sequence.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_token
  {
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

      struct TestNoSpace :
        mpllibs::test::test_equal<
          mpllibs::parser::token<testParser>::apply<helloString>::type::first,
          testParser::apply<helloString>::type::first
        >
      {};

      struct TestSpaces :
        mpllibs::test::test_equal<
          mpllibs::parser::token<
            testParser
          >::apply<helloSpaceString>::type::first,
          testParser::apply<helloString>::type::first
        >
      {};

      struct TestSpacesConsumed :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::token<
            testParser
          >::apply<helloSpaceString>::type::second,
          boost::mpl::list_c<char>
        >
      {};
      
      struct TestFail :
        mpllibs::test::test_equal<
          mpllibs::parser::token<testParser>::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

