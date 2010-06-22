// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/iterate.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/equal_sequence.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        int13
      >::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Iterate_TestEmptyInput;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        int0
      >::apply<str_hello>::type::first,
      boost::mpl::list<>
    >
    Iterate_Test0;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        int1
      >::apply<str_hello>::type::first,
      boost::mpl::list<char_h>
    >
    Iterate_Test1;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        int2
      >::apply<str_hello>::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Iterate_Test2;

  typedef
    mpllibs::test::equal_sequence<
      mpllibs::parser::iterate<
        mpllibs::parser::one_char,
        int3
      >::apply<str_hello>::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Iterate_Test3;
}

MPLLIBS_ADD_TEST(Iterate_TestEmptyInput)
MPLLIBS_ADD_TEST(Iterate_Test0)
MPLLIBS_ADD_TEST(Iterate_Test1)
MPLLIBS_ADD_TEST(Iterate_Test2)
MPLLIBS_ADD_TEST(Iterate_Test3)

