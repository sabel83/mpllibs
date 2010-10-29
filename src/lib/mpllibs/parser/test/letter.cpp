// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/letter.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("letter");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::letter, str_hello>::type::first,
      char_h
    >
    TestWithText;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::letter, str_1983>::type,
      mpllibs::parser::nothing
    >
    TestWithNumber;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::letter, str_>::type,
      mpllibs::parser::nothing
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithNumber)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


