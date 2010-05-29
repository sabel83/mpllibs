#ifndef MPLLIBS_PARSER_LIT_C_H
#define MPLLIBS_PARSER_LIT_C_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/lit.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <char c>
    struct lit_c : mpllibs::parser::lit<boost::mpl::integral_c<char, c> >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

namespace mpllibs
{
  namespace test_mpllibs_parser_lit_c
  {
    namespace
    {
      typedef boost::mpl::integral_c<char, 'h'> hCharacter;
      typedef boost::mpl::integral_c<char, 'e'> eCharacter;
    
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char, 'b', 'e', 'l', 'l', 'o'> otherString;
      typedef boost::mpl::list_c<char> emptyString;

      struct TestAccept :
        mpllibs::test::test_equal<
          mpllibs::parser::lit_c<'h'>::apply<helloString>::type::first,
          hCharacter
        >
      {};    

      struct TestReject :
        mpllibs::test::test_equal<
          mpllibs::parser::lit_c<'h'>::apply<otherString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestWithEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::lit_c<'h'>::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestRemainingString :
        mpllibs::test::test_equal<
          mpllibs::parser::lit_c<'e'>::apply<
            mpllibs::parser::lit_c<'h'>::apply<helloString>::type::second
          >::type::first,
          eCharacter
        >
      {};    
    }
  }
}
#endif

#endif


