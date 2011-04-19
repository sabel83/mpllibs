// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/last_of.h>
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
  const mpllibs::metatest::TestSuite suite("last_of");

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::last_of<lit_h>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestOneChar;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::last_of<lit_h, lit_e>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_e
    >
    TestTwoChars;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::last_of<lit_x, lit_e>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestFirstFails;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::last_of<lit_h, lit_x>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestSecondFails;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::last_of<lit_h, lit_e>,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestEmptyInput;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::last_of<lit_h, lit_e, lit_l>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_l
    >
    TestThreeChars;
}

MPLLIBS_ADD_TEST(suite, TestOneChar)
MPLLIBS_ADD_TEST(suite, TestTwoChars)
MPLLIBS_ADD_TEST(suite, TestFirstFails)
MPLLIBS_ADD_TEST(suite, TestSecondFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, TestThreeChars)


