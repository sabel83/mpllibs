// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_second.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("keep_second");

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_h, lit_e>::apply<str_hello>::type::first,
      char_e
    >
    TestTwoChars;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_x, lit_e>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    TestFirstFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_h, lit_x>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    TestSecondFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_h, lit_e>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;
}

MPLLIBS_ADD_TEST(suite, TestTwoChars)
MPLLIBS_ADD_TEST(suite, TestFirstFails)
MPLLIBS_ADD_TEST(suite, TestSecondFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)


