// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/cons.h>

#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/pair.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("cons");
  
  typedef boost::mpl::int_<11> int11;
  typedef boost::mpl::int_<13> int13;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::util::cons,
        boost::mpl::pair<int11, boost::mpl::list<int13> >
      >::type,
      boost::mpl::list<int11, int13>
    >
    TestPushingToList;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::apply<
        mpllibs::util::cons,
        boost::mpl::pair<int13, boost::mpl::list< > >
      >::type,
      boost::mpl::list<int13>
    >
    TestPushingToEmptyList;
}

MPLLIBS_ADD_TEST(suite, TestPushingToList)
MPLLIBS_ADD_TEST(suite, TestPushingToEmptyList)

