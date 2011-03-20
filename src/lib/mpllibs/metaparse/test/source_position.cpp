// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/next_char.h>
#include <mpllibs/metaparse/next_line.h>
#include <mpllibs/metaparse/get_prev_char.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("source_position");
  
  typedef
    boost::mpl::equal_to<
      int11,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::source_position<int11, int13, int1>
      >::type
    >
    TestGetLine;

  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::metaparse::get_col<
        mpllibs::metaparse::source_position<int11, int13, int1>
      >::type
    >
    TestGetCol;
  
  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_prev_char<
        mpllibs::metaparse::source_position<int11, int13, int1>
      >::type
    >
    TestGetPrevChar;

  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_line<mpllibs::metaparse::start>::type
    >
    TestLineOfStart;

  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_col<mpllibs::metaparse::start>::type
    >
    TestColOfStart;

  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_col<
        mpllibs::metaparse::next_char<mpllibs::metaparse::start, char_0>
      >::type
    >
    TestNextCharsChar;

  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::next_char<mpllibs::metaparse::start, char_0>
      >::type
    >
    TestNextCharsLine;

  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_col<
        mpllibs::metaparse::next_line<
          mpllibs::metaparse::next_char<mpllibs::metaparse::start, char_0>,
          char_0
        >
      >::type
    >
    TestNextLinesChar;

  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::next_line<mpllibs::metaparse::start, char_0>
      >::type
    >
    TestNextLinesLine;

  typedef
    boost::mpl::equal_to<
      char_1,
      mpllibs::metaparse::get_prev_char<
        mpllibs::metaparse::next_char<mpllibs::metaparse::start, char_1>
      >::type
    >
    TestNextCharsPrevChar;

  typedef
    boost::mpl::equal_to<
      char_1,
      mpllibs::metaparse::get_prev_char<
        mpllibs::metaparse::next_line<mpllibs::metaparse::start, char_1>
      >::type
    >
    TestNextLinesPrevChar;
}

MPLLIBS_ADD_TEST(suite, TestGetLine)
MPLLIBS_ADD_TEST(suite, TestGetCol)
MPLLIBS_ADD_TEST(suite, TestGetPrevChar)

MPLLIBS_ADD_TEST(suite, TestLineOfStart)
MPLLIBS_ADD_TEST(suite, TestColOfStart)

MPLLIBS_ADD_TEST(suite, TestNextCharsChar)
MPLLIBS_ADD_TEST(suite, TestNextCharsLine)
MPLLIBS_ADD_TEST(suite, TestNextLinesChar)
MPLLIBS_ADD_TEST(suite, TestNextLinesLine)

MPLLIBS_ADD_TEST(suite, TestNextCharsPrevChar)
MPLLIBS_ADD_TEST(suite, TestNextLinesPrevChar)


