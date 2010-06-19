// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/iterate.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_equal_sequence.h>
#include <mpllibs/test/test_equal.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>

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
      boost::mpl::list<hCharacter>
    >
  {};

  struct Test2 :
    mpllibs::test::test_equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<2>
      >::apply<helloString>::type::first,
      boost::mpl::list<hCharacter, eCharacter>
    >
  {};

  struct Test3 :
    mpllibs::test::test_equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<3>
      >::apply<helloString>::type::first,
      boost::mpl::list<hCharacter, eCharacter, lCharacter>
    >
  {};
}

