// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/cons.h>

#include "common.h"

#include <mpllibs/metatest/equal_sequence.h>
#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/pair.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("cons");
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::util::cons,
        boost::mpl::pair<int11, boost::mpl::list<int13> >
      >::type,
      boost::mpl::list<int11, int13>
    >
    TestPushingToList;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::util::cons,
        boost::mpl::pair<int13, empty_list>
      >::type,
      boost::mpl::list<int13>
    >
    TestPushingToEmptyList;
}

MPLLIBS_ADD_TEST(suite, TestPushingToList)
MPLLIBS_ADD_TEST(suite, TestPushingToEmptyList)

