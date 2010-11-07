// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/util/is_nothing.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("fail");

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<mpllibs::metaparse::fail, str_hello>
    >
    TestFailForNonEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestFailForNonEmptyString)


