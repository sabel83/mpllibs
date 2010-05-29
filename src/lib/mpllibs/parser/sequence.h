#ifndef MPLLIBS_PARSER_SEQUENCE_H
#define MPLLIBS_PARSER_SEQUENCE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/nothing.h>

#include <mpllibs/util/pair.h>
#include <mpllibs/util/get_first.h>
#include <mpllibs/util/get_second.h>
#include <mpllibs/util/make_pair.h>
#include <mpllibs/util/lazy_equal_to.h>
#include <mpllibs/util/compose.h>

#include <boost/mpl/if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p1, class p2>
    struct sequence
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          mpllibs::util::lazy_equal_to<
            boost::mpl::apply<p1, S>,
            mpllibs::parser::nothing
          >,
          mpllibs::parser::nothing,
          boost::mpl::eval_if<
            mpllibs::util::lazy_equal_to<
              boost::mpl::apply<
                mpllibs::util::compose<p2, mpllibs::util::get_second, p1>,
                S
              >,
              mpllibs::parser::nothing
            >,
            mpllibs::parser::nothing,
            mpllibs::util::make_pair<
              mpllibs::util::make_pair<
                boost::mpl::apply<
                  mpllibs::util::compose<mpllibs::util::get_first, p1>,
                  S
                >,
                boost::mpl::apply<
                  mpllibs::util::compose<
                    mpllibs::util::get_first,
                    p2,
                    mpllibs::util::get_second,
                    p1
                  >,
                  S
                >
              >,
              boost::mpl::apply<
                mpllibs::util::compose<
                  mpllibs::util::get_second,
                  p2,
                  mpllibs::util::get_second,
                  p1
                >,
                S
              >
            >
          >
        >
      {};
    };
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
  namespace test_mpllibs_parser_sequence
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
          mpllibs::parser::sequence<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<eCharacter>
          >::apply<helloString>::type::first,
          mpllibs::util::pair<hCharacter, eCharacter>
        >
      {};

      struct TestFirstFails :
        mpllibs::test::test_equal<
          mpllibs::parser::sequence<
            mpllibs::parser::lit<xCharacter>,
            mpllibs::parser::lit<eCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestSecondFails :
        mpllibs::test::test_equal<
          mpllibs::parser::sequence<
            mpllibs::parser::lit<hCharacter>,
            mpllibs::parser::lit<xCharacter>
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestEmptyInput :
        mpllibs::test::test_equal<
          mpllibs::parser::sequence<
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

