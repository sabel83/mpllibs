#ifndef MPLLIBS_PARSER_FIRST_OF_H
#define MPLLIBS_PARSER_FIRST_OF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/transform.h>
#include <mpllibs/parser/sequence.h>

#include <mpllibs/util/get_first.h>

namespace mpllibs
{
  namespace parser
  {
    template <class p1, class p2>
    struct first_of :
      mpllibs::parser::transform<
        mpllibs::parser::sequence<p1, p2>,
        mpllibs::util::get_first
      >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_first_of
  {
    namespace
    {
      typedef boost::mpl::integral_c<char, 'h'> hCharacter;
      typedef boost::mpl::integral_c<char, 'e'> eCharacter;
      typedef boost::mpl::integral_c<char, 'x'> xCharacter;
      
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char> emptyString;

      struct TestTwoChars :
        mpllibs::test::test_equal<
          mpllibs::parser::first_of<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<eCharacter>
          >::apply<helloString>::type::first,
          hCharacter
        >
      {};

      struct TestFirstFails :
        mpllibs::test::test_equal<
          mpllibs::parser::first_of<
            mpllibs::parser::lit<xCharacter>,
            mpllibs::parser::lit<eCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestSecondFails :
        mpllibs::test::test_equal<
          mpllibs::parser::first_of<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<xCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestEmptyInput :
        mpllibs::test::test_equal<
          mpllibs::parser::first_of<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<eCharacter>
          >::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

