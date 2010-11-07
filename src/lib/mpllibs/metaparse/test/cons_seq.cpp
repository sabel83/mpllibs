// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/cons_seq.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::cons_seq");
  
  typedef
    boost::mpl::equal<
      boost::mpl::apply<
        mpllibs::metaparse::util::cons_seq,
        boost::mpl::deque<int11, boost::mpl::list<int13> >
      >::type,
      boost::mpl::list<int11, int13>
    >
    TestPushingToList;

  typedef
    boost::mpl::equal<
      boost::mpl::apply<
        mpllibs::metaparse::util::cons_seq,
        boost::mpl::deque<int13, empty_list>
      >::type,
      boost::mpl::list<int13>
    >
    TestPushingToEmptyList;
}

MPLLIBS_ADD_TEST(suite, TestPushingToList)
MPLLIBS_ADD_TEST(suite, TestPushingToEmptyList)

