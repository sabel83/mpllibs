// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/version.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_version)
{
  // verifying that the version numbers coming from the build system are the
  // same as the ones defined in the headers

  BOOST_CHECK_EQUAL(MPLLIBS_MAJOR_VERSION, BUILD_MAJOR_VERSION);
  BOOST_CHECK_EQUAL(MPLLIBS_MINOR_VERSION, BUILD_MINOR_VERSION);
  BOOST_CHECK_EQUAL(MPLLIBS_PATCH_VERSION, BUILD_PATCH_VERSION);
}



