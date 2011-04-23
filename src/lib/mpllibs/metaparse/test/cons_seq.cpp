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

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::util::cons_seq;

using boost::mpl::equal;
using boost::mpl::apply;
using boost::mpl::list;
using boost::mpl::deque;

namespace
{
  const TestSuite suite("util::cons_seq");
  
  typedef
    equal<
      apply<cons_seq, deque<int11, list<int13> > >::type,
      list<int11, int13>
    >
    test_pushing_to_list;

  typedef
    equal<
      apply<cons_seq, deque<int13, empty_list> >::type,
      list<int13>
    >
    test_pushing_to_empty_list;
}

MPLLIBS_ADD_TEST(suite, test_pushing_to_list)
MPLLIBS_ADD_TEST(suite, test_pushing_to_empty_list)

