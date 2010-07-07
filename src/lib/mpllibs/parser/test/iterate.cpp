// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/iterate.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("iterate");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::iterate<mpllibs::parser::one_char, int13>,
        str_
      >::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::iterate<mpllibs::parser::one_char, int0>,
        str_hello
      >::type::first,
      boost::mpl::list<>
    >
    Test0;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::iterate<mpllibs::parser::one_char, int1>,
        str_hello
      >::type::first,
      boost::mpl::list<char_h>
    >
    Test1;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::iterate<mpllibs::parser::one_char, int2>,
        str_hello
      >::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Test2;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::parser::iterate<mpllibs::parser::one_char, int3>,
        str_hello
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Test3;
}

MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test1)
MPLLIBS_ADD_TEST(suite, Test2)
MPLLIBS_ADD_TEST(suite, Test3)

