// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/util/id.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using boost::mpl::int_;
using boost::mpl::equal_to;

using mpllibs::metatest::test_suite;

using mpllibs::error::util::id;

namespace
{
  const test_suite suite("util::id");

  typedef int_<13> int13;

  typedef equal_to<int13, id<int13>::type> test_identity;
}

MPLLIBS_ADD_TEST(suite, test_identity)

