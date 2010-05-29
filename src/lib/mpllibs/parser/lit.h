#ifndef MPLLIBS_PARSER_LIT_H
#define MPLLIBS_PARSER_LIT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/accept_when.h>
#include <mpllibs/parser/one_char.h>

#include <mpllibs/util/is_char.h>

namespace mpllibs
{
  namespace parser
  {
    template <class c>
    struct lit :
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_char<c>
      >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_lit
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
          mpllibs::parser::lit<hCharacter>::apply<helloString>::type::first,
          hCharacter
        >
      {};    

      struct TestReject :
        mpllibs::test::test_equal<
          mpllibs::parser::lit<hCharacter>::apply<otherString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestWithEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::lit<hCharacter>::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestRemainingString :
        mpllibs::test::test_equal<
          mpllibs::parser::lit<eCharacter>::apply<
            mpllibs::parser::lit<hCharacter>::apply<helloString>::type::second
          >::type::first,
          eCharacter
        >
      {};    
    }
  }
}
#endif

#endif


