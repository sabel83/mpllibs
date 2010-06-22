// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_second.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_h, lit_e>::apply<str_hello>::type::first,
      char_e
    >
    KeepSecond_TestTwoChars;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_x, lit_e>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepSecond_TestFirstFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_h, lit_x>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepSecond_TestSecondFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_second<lit_h, lit_e>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    KeepSecond_TestEmptyInput;
}

MPLLIBS_ADD_TEST(KeepSecond_TestTwoChars)
MPLLIBS_ADD_TEST(KeepSecond_TestFirstFails)
MPLLIBS_ADD_TEST(KeepSecond_TestSecondFails)
MPLLIBS_ADD_TEST(KeepSecond_TestEmptyInput)


