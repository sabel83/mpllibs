// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/util/id.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::id");

  typedef boost::mpl::int_<13> int13;

  typedef
    boost::mpl::equal_to<int13, mpllibs::error::util::id<int13>::type>
    TestIdentity;
}

MPLLIBS_ADD_TEST(suite, TestIdentity)

