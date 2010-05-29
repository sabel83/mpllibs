#ifndef MPLLIBS_PARSER_ITERATE_H
#define MPLLIBS_PARSER_ITERATE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/sequence.h>
#include <mpllibs/parser/return.h>
#include <mpllibs/parser/transform.h>

#include <mpllibs/util/cons.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/int.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/minus.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <class p, class n>
    struct iterate :
      boost::mpl::if_<
        typename boost::mpl::equal_to<n, boost::mpl::int_<0> >::type,
        mpllibs::parser::return_<boost::mpl::list<> >,
        mpllibs::parser::transform<
         typename mpllibs::parser::sequence<
            p,
            typename mpllibs::parser::iterate<
              p,
              typename boost::mpl::minus<n, boost::mpl::int_<1> >::type
            >
          >,
          mpllibs::util::cons
        >
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
  namespace test_mpllibs_parser_iterate
  {
    namespace
    {
      typedef boost::mpl::integral_c<char, 'h'> hCharacter;
      typedef boost::mpl::integral_c<char, 'e'> eCharacter;
      typedef boost::mpl::integral_c<char, 'l'> lCharacter;
      
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char> emptyString;

      struct TestEmptyInput :
        mpllibs::test::test_equal<
          mpllibs::parser::iterate<
            mpllibs::parser::one_char,
            boost::mpl::int_<13>
          >::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct Test0 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::iterate<
            mpllibs::parser::one_char,
            boost::mpl::int_<0>
          >::apply<helloString>::type::first,
          boost::mpl::list<>
        >
      {};

      struct Test1 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::iterate<
            mpllibs::parser::one_char,
            boost::mpl::int_<1>
          >::apply<helloString>::type::first,
          boost::mpl::list<
            hCharacter
          >
        >
      {};

      struct Test2 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::iterate<
            mpllibs::parser::one_char,
            boost::mpl::int_<2>
          >::apply<helloString>::type::first,
          boost::mpl::list<
            hCharacter,
            eCharacter
          >
        >
      {};

      struct Test3 :
        mpllibs::test::test_equal_sequence<
          mpllibs::parser::iterate<
            mpllibs::parser::one_char,
            boost::mpl::int_<3>
          >::apply<helloString>::type::first,
          boost::mpl::list<
            hCharacter,
            eCharacter,
            lCharacter
          >
        >
      {};
    }
  }
}
#endif

#endif

