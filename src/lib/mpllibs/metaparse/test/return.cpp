// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("return");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::return_<char_x>,
        str_hello
      >::type::first,
      char_x
    >
    TestForNonEmptyString;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::return_<char_x>, str_>::type::first,
      char_x
    >
    TestForEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestForEmptyString)
MPLLIBS_ADD_TEST(suite, TestForNonEmptyString)


