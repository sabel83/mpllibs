// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/fail.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/not.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("is_error");
  
  typedef boost::mpl::not_<mpllibs::metaparse::is_error<int13> > TestNotError;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::fail<int11>,
        int1,
        int13
      >
    >
    TestError;
}

MPLLIBS_ADD_TEST(suite, TestNotError)
MPLLIBS_ADD_TEST(suite, TestError)


