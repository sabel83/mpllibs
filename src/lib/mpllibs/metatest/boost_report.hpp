#ifndef MPLLIBS_METATEST_BOOST_REPORT_H
#define MPLLIBS_METATEST_BOOST_REPORT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/test/unit_test.hpp>
#include <string>

namespace mpllibs
{
  namespace metatest
  {
    boost::unit_test::test_suite* build_metatest_test_suite(
      const std::string& name_ = "metatest"
    );
  }
}

#endif



