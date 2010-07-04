// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/nothing.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("digit");

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    TestWithText;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_1983>::type::first,
      char_1
    >
    TestWithNumber;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_>::type,
      mpllibs::parser::nothing
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithNumber)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


