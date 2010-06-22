// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit_val.h>
#include <mpllibs/parser/nothing.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit_val::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    DigitVal_TestWithText;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit_val::apply<str_1983>::type::first,
      int1
    >
    DigitVal_TestWithNumber;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit_val::apply<str_>::type,
      mpllibs::parser::nothing
    >
    DigitVal_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(DigitVal_TestWithText)
MPLLIBS_ADD_TEST(DigitVal_TestWithNumber)
MPLLIBS_ADD_TEST(DigitVal_TestWithEmptyString)




