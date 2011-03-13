// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/next_char.h>
#include <mpllibs/metaparse/next_line.h>

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
        mpllibs::metaparse::source_position<int11, int13>
      >::type
    >
    TestGetLine;

  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::metaparse::get_col<
        mpllibs::metaparse::source_position<int11, int13>
      >::type
    >
    TestGetCol;
  
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
        mpllibs::metaparse::next_char<mpllibs::metaparse::start>
      >::type
    >
    TestNextCharsChar;

  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::next_char<mpllibs::metaparse::start>
      >::type
    >
    TestNextCharsLine;

  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_col<
        mpllibs::metaparse::next_line<mpllibs::metaparse::start>
      >::type
    >
    TestNextLinesChar;

  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::next_line<mpllibs::metaparse::start>
      >::type
    >
    TestNextLinesLine;
}

MPLLIBS_ADD_TEST(suite, TestGetLine)
MPLLIBS_ADD_TEST(suite, TestGetCol)

MPLLIBS_ADD_TEST(suite, TestLineOfStart)
MPLLIBS_ADD_TEST(suite, TestColOfStart)

MPLLIBS_ADD_TEST(suite, TestNextCharsChar)
MPLLIBS_ADD_TEST(suite, TestNextCharsLine)
MPLLIBS_ADD_TEST(suite, TestNextLinesChar)
MPLLIBS_ADD_TEST(suite, TestNextLinesLine)



