// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/letter.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::letter::apply<str_hello>::type::first,
      char_h
    >
    Letter_TestWithText;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::letter::apply<str_1983>::type,
      mpllibs::parser::nothing
    >
    Letter_TestWithNumber;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::letter::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Letter_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(Letter_TestWithText)
MPLLIBS_ADD_TEST(Letter_TestWithNumber)
MPLLIBS_ADD_TEST(Letter_TestWithEmptyString)


