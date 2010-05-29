#ifndef MPLLIBS_PARSER_KEYWORD_H
#define MPLLIBS_PARSER_KEYWORD_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/lit.h>
#include <mpllibs/parser/return.h>
#include <mpllibs/parser/sequence.h>
#include <mpllibs/parser/second_of.h>

#include <mpllibs/util/lazy_if.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>

namespace mpllibs
{
  namespace parser
  {
    struct accepted_keyword {};

    template <class s, class result_type>
    struct keyword;
    
    namespace impl
    {
      template <class s, class result_type>
      struct nonemptyKeyword :
        mpllibs::parser::second_of<
          mpllibs::parser::sequence<
            mpllibs::parser::lit<typename boost::mpl::front<s>::type>,
            mpllibs::parser::keyword<
              typename boost::mpl::pop_front<s>::type,
              result_type
            >
          >,
          mpllibs::parser::return_<result_type>
        >
      {};
    }
    
    // Does not consume/check anything after the keyword
    template <class s, class result_type = accepted_keyword>
    struct keyword :
      mpllibs::util::lazy_if<
        boost::mpl::empty<s>,
        mpllibs::parser::return_<result_type>,
        mpllibs::parser::impl::nonemptyKeyword<s, result_type>
      >::type
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_equal_sequence.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_keyword
  {
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
          mpllibs::parser::keyword<helloString>::apply<
            helloString
          >::type::second,
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
  }
}
#endif

#endif

