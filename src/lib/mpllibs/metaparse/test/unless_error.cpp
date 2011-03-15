// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_error.h>
#include <mpllibs/metaparse/is_error.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::unless_error");
  
  typedef mpllibs::metaparse::error<int1, int2> err;
  
  typedef
    mpllibs::metaparse::is_error<
      mpllibs::metaparse::util::unless_error<err, int13>
    >
    TestError;

  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::metaparse::util::unless_error<int11, int13>::type
    >
    TestNotError;
}

MPLLIBS_ADD_TEST(suite, TestError)
MPLLIBS_ADD_TEST(suite, TestNotError)

