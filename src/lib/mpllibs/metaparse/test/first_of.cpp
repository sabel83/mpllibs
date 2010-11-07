// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/first_of.h>
#include <mpllibs/metaparse/util/is_nothing.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("first_of");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::first_of<lit_h>,
        str_hello
      >::type::first,
      char_h
    >
    TestOneChar;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::first_of<lit_h, lit_e>,
        str_hello
      >::type::first,
      char_h
    >
    TestTwoChars;

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<
        mpllibs::metaparse::first_of<lit_x, lit_e>,
        str_hello
      >
    >
    TestFirstFails;

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<
        mpllibs::metaparse::first_of<lit_h, lit_x>,
        str_hello
      >
    >
    TestSecondFails;

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<mpllibs::metaparse::first_of<lit_h, lit_e>, str_>
    >
    TestEmptyInput;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::first_of<lit_h, lit_e, lit_l>,
        str_hello
      >::type::first,
      char_h
    >
    TestThreeChars;
}

MPLLIBS_ADD_TEST(suite, TestOneChar)
MPLLIBS_ADD_TEST(suite, TestTwoChars)
MPLLIBS_ADD_TEST(suite, TestFirstFails)
MPLLIBS_ADD_TEST(suite, TestSecondFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, TestThreeChars)

