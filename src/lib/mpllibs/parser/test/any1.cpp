// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/any1.h>
#include <mpllibs/parser/letter.h>

#include "common.h"
 
#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{ 
  const mpllibs::test::TestSuite suite("any1");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        str_
      >::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        chars0
      >::type,
      mpllibs::parser::nothing
    >
    Test0;
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        chars1
      >::type::first,
      boost::mpl::list<char_h>
    >
    Test1;
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        chars2
      >::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Test2;
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        chars3
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Test3;
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        chars4
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l, char_l>
    >
    Test4;
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::any1<mpllibs::parser::letter>,
        chars5
      >::type::first,
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


