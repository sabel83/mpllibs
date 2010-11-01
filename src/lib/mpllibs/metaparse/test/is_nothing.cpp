// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_nothing.h>
#include <mpllibs/metaparse/util/pair.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/not.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::is_nothing");
  
  typedef
    mpllibs::metaparse::util::is_nothing<mpllibs::metaparse::nothing>
    TestNothing;

  typedef
    boost::mpl::not_<
      mpllibs::metaparse::util::is_nothing<
        mpllibs::metaparse::util::pair<
          mpllibs::metaparse::nothing,
          mpllibs::metaparse::nothing
        >
      >
    >
    TestPairOfNothings;
}

MPLLIBS_ADD_TEST(suite, TestNothing)
MPLLIBS_ADD_TEST(suite, TestPairOfNothings)

