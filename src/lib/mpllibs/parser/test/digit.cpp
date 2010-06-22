// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/nothing.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Digit_TestWithText;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_1983>::type::first,
      char_1
    >
    Digit_TestWithNumber;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Digit_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(Digit_TestWithText)
MPLLIBS_ADD_TEST(Digit_TestWithNumber)
MPLLIBS_ADD_TEST(Digit_TestWithEmptyString)


