// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any.h>
#include <mpllibs/parser/letter.h>

#include "common.h"
 
#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

namespace
{ 
  typedef boost::mpl::list_c<char, '0', 'e', 'l', 'l', 'o'> chars0;
  typedef boost::mpl::list_c<char, 'h', '0', 'l', 'l', 'o'> chars1;
  typedef boost::mpl::list_c<char, 'h', 'e', '0', 'l', 'o'> chars2;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', '0', 'o'> chars3;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', '0'> chars4;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> chars5;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<str_>::type::first,
      boost::mpl::list<>
    >
    Any_TestEmptyInput;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars0>::type::first,
      boost::mpl::list<>
    >
    Any_Test0;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars1>::type::first,
      boost::mpl::list<char_h>
    >
    Any_Test1;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars2>::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Any_Test2;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars3>::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Any_Test3;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars4>::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l>
    >
    Any_Test4;
  
  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::any<mpllibs::parser::letter>::apply<chars5>::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l, char_o>
    >
    Any_Test5;
}

MPLLIBS_ADD_TEST(Any_TestEmptyInput)
MPLLIBS_ADD_TEST(Any_Test0)
MPLLIBS_ADD_TEST(Any_Test1)
MPLLIBS_ADD_TEST(Any_Test2)
MPLLIBS_ADD_TEST(Any_Test3)
MPLLIBS_ADD_TEST(Any_Test4)
MPLLIBS_ADD_TEST(Any_Test5)

