// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("accept");
  
  typedef mpllibs::metaparse::accept<int1, int2, int3> Acc;
  
  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_result<Acc>::type
    >
    TestGetResult;

  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_remaining<Acc>::type
    >
    TestGetRemaining;

  typedef
    boost::mpl::equal_to<
      int3,
      mpllibs::metaparse::get_position<Acc>::type
    >
    TestGetPosition;
}

MPLLIBS_ADD_TEST(suite, TestGetResult)
MPLLIBS_ADD_TEST(suite, TestGetRemaining)
MPLLIBS_ADD_TEST(suite, TestGetPosition)


