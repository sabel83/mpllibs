// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/always.h>
#include <mpllibs/metaparse/nothing.h>
#include <mpllibs/metaparse/digit.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("always");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::always<mpllibs::metaparse::digit, int13>,
        str_1
      >::type::first,
      int13
    >
    TestResult;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::always<mpllibs::metaparse::digit, int13>,
        str_a
      >::type,
      mpllibs::metaparse::nothing
    >
    TestFail;
}

MPLLIBS_ADD_TEST(suite, TestResult)
MPLLIBS_ADD_TEST(suite, TestFail)

