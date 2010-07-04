// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any.h>
#include <mpllibs/parser/letter.h>

#include "common.h"
 
#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/TestSuite.h>

namespace
{ 
  const mpllibs::test::TestSuite suite("any");

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<str_>::type::first,
      boost::mpl::list<>
    >
    TestEmptyInput;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars0>::type::first,
      boost::mpl::list<>
    >
    Test0;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars1>::type::first,
      boost::mpl::list<char_h>
    >
    Test1;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars2>::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Test2;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars3>::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Test3;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars4>::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l>
    >
    Test4;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars5>::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l, char_o>
    >
    Test5;
}

MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test1)
MPLLIBS_ADD_TEST(suite, Test2)
MPLLIBS_ADD_TEST(suite, Test3)
MPLLIBS_ADD_TEST(suite, Test4)
MPLLIBS_ADD_TEST(suite, Test5)

