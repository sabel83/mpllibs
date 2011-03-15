// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/always.h>
#include <mpllibs/metaparse/error.h>
#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("always");

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::always<mpllibs::metaparse::digit, int13>,
          str_1,
          mpllibs::metaparse::start
        >
      >::type,
      int13
    >
    TestResult;
  
  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::always<mpllibs::metaparse::digit, int13>,
        str_a,
        mpllibs::metaparse::start
      >
    >
    TestFail;
}

MPLLIBS_ADD_TEST(suite, TestResult)
MPLLIBS_ADD_TEST(suite, TestFail)

