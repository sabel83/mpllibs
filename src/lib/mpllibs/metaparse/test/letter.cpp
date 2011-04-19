// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/letter.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

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
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::letter,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestWithText;
  
  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::letter,
        str_1983,
        mpllibs::metaparse::start
      >
    >
    TestWithNumber;
  
  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::letter,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithNumber)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


