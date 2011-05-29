// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/cons.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::cons;

using boost::mpl::equal;
using boost::mpl::apply;
using boost::mpl::pair;
using boost::mpl::list;

namespace
{
  const suite_path suite = suite_path("util")("cons");
  
  typedef
    equal<apply<cons, pair<int11, list<int13> > >::type, list<int11, int13> >
    test_pushing_to_list;

  typedef
    equal<apply<cons, pair<int13, empty_list> >::type, list<int13> >
    test_pushing_to_empty_list;
}

MPLLIBS_ADD_TEST(suite, test_pushing_to_list)
MPLLIBS_ADD_TEST(suite, test_pushing_to_empty_list)

