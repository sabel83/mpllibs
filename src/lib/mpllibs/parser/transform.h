#ifndef MPLLIBS_PARSER_TRANSFORM_H
#define MPLLIBS_PARSER_TRANSFORM_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/nothing.h>

#include <mpllibs/util/pair.h>
#include <mpllibs/util/get_first.h>
#include <mpllibs/util/get_second.h>
#include <mpllibs/util/make_pair.h>
#include <mpllibs/util/compose.h>
#include <mpllibs/util/lazy_equal_to.h>
#include <mpllibs/util/lazy_eval_if.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class t>
    struct transform
    {
      template <class S>
      struct apply :
        boost::mpl::eval_if<
          mpllibs::util::lazy_equal_to<
            boost::mpl::apply<p, S>,
            mpllibs::parser::nothing
          >,
          mpllibs::parser::nothing,
          mpllibs::util::make_pair<
            boost::mpl::apply<
              mpllibs::util::compose<t, mpllibs::util::get_first, p>,
              S
            >,
            boost::mpl::apply<
              mpllibs::util::compose<mpllibs::util::get_second, p>,
              S
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

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_parser_transform
  {
    namespace
    {
      struct transformation
      {
        template <class t>
        struct apply
        {
          typedef boost::mpl::integral_c<char, 'x'> type;
        };
      };
    
      typedef boost::mpl::integral_c<char, 'h'> hCharacter;
      typedef boost::mpl::integral_c<char, 'e'> eCharacter;
      typedef boost::mpl::integral_c<char, 'x'> xCharacter;
      
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char> emptyString;

      struct TestNormalCase :
        mpllibs::test::test_equal<
          mpllibs::parser::transform<
            mpllibs::parser::lit<hCharacter>,
            transformation
          >::apply<helloString>::type::first,
          xCharacter
        >
      {};

      struct TestParserFails :
        mpllibs::test::test_equal<
          mpllibs::parser::transform<
            mpllibs::parser::lit<xCharacter>,
            transformation
          >::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestEmptyInput :
        mpllibs::test::test_equal<
          mpllibs::parser::transform<
            mpllibs::parser::lit<hCharacter>,
            transformation
          >::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

