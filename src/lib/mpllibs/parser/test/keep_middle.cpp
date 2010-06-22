// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_middle.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_middle<
        lit_h,
        lit_e,
        lit_l
      >::apply<str_hello>::type::first,
      char_e
    >
    KeepMiddle_TestThreeChars;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_middle<lit_x, lit_e, lit_l>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepMiddle_TestFirstFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_middle<lit_h, lit_x, lit_l>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepMiddle_TestSecondFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_middle<lit_h, lit_e, lit_x>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    KeepMiddle_TestThirdFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_middle<lit_h, lit_e, lit_l>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    KeepMiddle_TestEmptyInput;
}

MPLLIBS_ADD_TEST(KeepMiddle_TestThreeChars)
MPLLIBS_ADD_TEST(KeepMiddle_TestFirstFails)
MPLLIBS_ADD_TEST(KeepMiddle_TestSecondFails)
MPLLIBS_ADD_TEST(KeepMiddle_TestThirdFails)
MPLLIBS_ADD_TEST(KeepMiddle_TestEmptyInput)


