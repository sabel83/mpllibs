#ifndef MPLLIBS_METATEST_MAIN_BOOST_H
#define MPLLIBS_METATEST_MAIN_BOOST_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/boost_report.h>

#include <boost/test/included/unit_test.hpp>

// To keep gcc with -Wmissing-declarations happy
boost::unit_test::test_suite* init_unit_test_suite(int, char*[]);

boost::unit_test::test_suite* init_unit_test_suite(int, char*[])
{
  return mpllibs::metatest::build_metatest_test_suite();
}

#endif

