#ifndef MPLLIBS_PARSER_KEEP_MIDDLE_H
#define MPLLIBS_PARSER_KEEP_MIDDLE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_first.h>
#include <mpllibs/parser/keep_second.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p1, class p2, class p3>
    struct keep_middle :
      mpllibs::parser::keep_second<p1, mpllibs::parser::keep_first<p2, p3> >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/lit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_keep_middle
  {
    namespace
    {
      typedef boost::mpl::integral_c<char, 'h'> hCharacter;
      typedef boost::mpl::integral_c<char, 'e'> eCharacter;
      typedef boost::mpl::integral_c<char, 'l'> lCharacter;
      typedef boost::mpl::integral_c<char, 'x'> xCharacter;
      
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char> emptyString;

      struct TestThreeChars :
        mpllibs::test::test_equal<
          mpllibs::parser::keep_middle<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<eCharacter>,
            mpllibs::parser::lit<lCharacter>
          >::apply<helloString>::type::first,
          eCharacter
        >
      {};

      struct TestFirstFails :
        mpllibs::test::test_equal<
          mpllibs::parser::keep_middle<
            mpllibs::parser::lit<xCharacter>,
            mpllibs::parser::lit<eCharacter>,
            mpllibs::parser::lit<lCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestSecondFails :
        mpllibs::test::test_equal<
          mpllibs::parser::keep_middle<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<xCharacter>,
            mpllibs::parser::lit<lCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestThirdFails :
        mpllibs::test::test_equal<
          mpllibs::parser::keep_middle<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<eCharacter>,
            mpllibs::parser::lit<xCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestEmptyInput :
        mpllibs::test::test_equal<
          mpllibs::parser::keep_middle<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<eCharacter>,
            mpllibs::parser::lit<lCharacter>
          >::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

