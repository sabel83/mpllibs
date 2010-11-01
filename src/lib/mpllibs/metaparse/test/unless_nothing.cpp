// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_nothing.h>
#include <mpllibs/metaparse/util/pair.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::unless_nothing");
  
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::util::unless_nothing<
        mpllibs::metaparse::nothing,
        int13
      >::type,
      mpllibs::metaparse::nothing
    >
    TestNothing;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::util::unless_nothing<
        mpllibs::metaparse::util::pair<
          mpllibs::metaparse::nothing,
          mpllibs::metaparse::nothing
        >,
        int13
      >::type,
      int13
    >
    TestPairOfNothings;
}

MPLLIBS_ADD_TEST(suite, TestNothing)
MPLLIBS_ADD_TEST(suite, TestPairOfNothings)

