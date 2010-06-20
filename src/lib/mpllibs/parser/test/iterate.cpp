// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/iterate.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::integral_c<char, 'h'> hCharacter;
  typedef boost::mpl::integral_c<char, 'e'> eCharacter;
  typedef boost::mpl::integral_c<char, 'l'> lCharacter;
      
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char> emptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<13>
      >::apply<emptyString>::type,
      mpllibs::parser::nothing
    >::type
    Iterate_TestEmptyInput;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<0>
      >::apply<helloString>::type::first,
      boost::mpl::list<>
    >::type
    Iterate_Test0;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<1>
      >::apply<helloString>::type::first,
      boost::mpl::list<hCharacter>
    >::type
    Iterate_Test1;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<2>
      >::apply<helloString>::type::first,
      boost::mpl::list<hCharacter, eCharacter>
    >::type
    Iterate_Test2;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        boost::mpl::int_<3>
      >::apply<helloString>::type::first,
      boost::mpl::list<hCharacter, eCharacter, lCharacter>
    >::type
    Iterate_Test3;
}

MPLLIBS_ADD_TEST(Iterate_TestEmptyInput)
MPLLIBS_ADD_TEST(Iterate_Test0)
MPLLIBS_ADD_TEST(Iterate_Test1)
MPLLIBS_ADD_TEST(Iterate_Test2)
MPLLIBS_ADD_TEST(Iterate_Test3)

