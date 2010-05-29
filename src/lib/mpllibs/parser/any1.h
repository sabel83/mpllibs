#ifndef MPLLIBS_PARSER_ANY1_H
#define MPLLIBS_PARSER_ANY1_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p>
    struct any1 :
      mpllibs::parser::transform<
        mpllibs::parser::sequence<p, mpllibs::parser::any<p> >,
        mpllibs::util::cons
      >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/letter.h>
 
#include <mpllibs/test/test_equal_sequence.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{ 
  namespace test_mpllibs_parser_any1
  {
    namespace
    {
      typedef boost::mpl::integral_c<char, 'h'> hCharacter;
      typedef boost::mpl::integral_c<char, 'e'> eCharacter;
      typedef boost::mpl::integral_c<char, 'l'> lCharacter;
      typedef boost::mpl::integral_c<char, 'o'> oCharacter;
      
      typedef boost::mpl::list_c<char, '0', 'e', 'l', 'l', 'o'> chars0;
      typedef boost::mpl::list_c<char, 'h', '0', 'l', 'l', 'o'> chars1;
      typedef boost::mpl::list_c<char, 'h', 'e', '0', 'l', 'o'> chars2;
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', '0', 'o'> chars3;
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', '0'> chars4;
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> chars5;
      typedef boost::mpl::list_c<char> emptyString;

      struct TestEmptyInput :
        mpllibs::test::test_equal<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct Test0 :
        mpllibs::test::test_equal<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<chars0>::type,
          mpllibs::parser::nothing
        >
      {};

      struct Test1 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<chars1>::type::first,
          boost::mpl::list<hCharacter>
        >
      {};

      struct Test2 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<chars2>::type::first,
          boost::mpl::list<hCharacter, eCharacter>
        >
      {};

      struct Test3 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<chars3>::type::first,
          boost::mpl::list<hCharacter, eCharacter, lCharacter>
        >
      {};
      
      struct Test4 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<chars4>::type::first,
          boost::mpl::list<hCharacter, eCharacter, lCharacter, lCharacter>
        >
      {};

      struct Test5 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::any1<
            mpllibs::parser::letter
          >::apply<chars5>::type::first,
          boost::mpl::list<
            hCharacter,
            eCharacter,
            lCharacter,
            lCharacter,
            oCharacter
          >
        >
      {};
    }
  }
}
#endif

#endif

