// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_first.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<lit_h, lit_e>::apply<str_hello>::type::first,
      char_h
    >
    KeepFirst_TestTwoChars;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<lit_x, lit_e>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepFirst_TestFirstFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<lit_h, lit_x>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepFirst_TestSecondFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<lit_h, lit_e>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    KeepFirst_TestEmptyInput;
}

MPLLIBS_ADD_TEST(KeepFirst_TestTwoChars)
MPLLIBS_ADD_TEST(KeepFirst_TestFirstFails)
MPLLIBS_ADD_TEST(KeepFirst_TestSecondFails)
MPLLIBS_ADD_TEST(KeepFirst_TestEmptyInput)

