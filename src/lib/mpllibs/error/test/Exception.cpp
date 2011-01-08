// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/Exception.h>

#include <mpllibs/error/get_data.h>
#include <mpllibs/error/get_location.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("Exception");

  typedef mpllibs::error::Exception<int11, int13> e;

  typedef
    boost::mpl::equal_to<int11, mpllibs::error::get_data<e>::type>
    TestGetData;

  typedef
    boost::mpl::equal_to<int13, mpllibs::error::get_location<e>::type>
    TestGetLocation;
}

MPLLIBS_ADD_TEST(suite, TestGetData)
MPLLIBS_ADD_TEST(suite, TestGetLocation)


