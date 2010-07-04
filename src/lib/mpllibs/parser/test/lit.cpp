// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("lit");

  typedef
    boost::mpl::equal_to<lit_h::apply<str_hello>::type::first, char_h>
    TestAccept;

  typedef
    boost::mpl::equal_to<
      lit_h::apply<str_bello>::type,
      mpllibs::parser::nothing
    >
    TestReject;

  typedef
    boost::mpl::equal_to<lit_h::apply<str_>::type, mpllibs::parser::nothing>
    TestWithEmptyString;

  typedef
    boost::mpl::equal_to<
      lit_e::apply<lit_h::apply<str_hello>::type::second>::type::first,
      char_e
    >
    TestRemainingString;
}

MPLLIBS_ADD_TEST(suite, TestAccept)
MPLLIBS_ADD_TEST(suite, TestReject)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)
MPLLIBS_ADD_TEST(suite, TestRemainingString)


