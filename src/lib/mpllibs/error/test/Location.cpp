// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/Location.h>

#include <mpllibs/error/get_file.h>
#include <mpllibs/error/get_line.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("Location");

  typedef mpllibs::error::Location<int11, int13> l;

  typedef
    boost::mpl::equal_to<int11, mpllibs::error::get_file<l>::type>
    TestGetData;

  typedef
    boost::mpl::equal_to<int13, mpllibs::error::get_line<l>::type>
    TestGetLocation;
}

MPLLIBS_ADD_TEST(suite, TestGetData)
MPLLIBS_ADD_TEST(suite, TestGetLocation)


