// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/cons_seq.hpp>

#include "common.hpp"

#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_cons_seq)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::util::cons_seq;
  
  using boost::mpl::equal;
  using boost::mpl::apply_wrap1;
  using boost::mpl::list;
  using boost::mpl::deque;

  meta_require<has_type<cons_seq> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal<
      apply_wrap1<cons_seq, deque<int11, list<int13> > >::type,
      list<int11, int13>
    >
  >(MPLLIBS_HERE, "test_pushing_to_list");

  meta_require<
    equal<
      apply_wrap1<cons_seq, deque<int13, empty_list> >::type,
      list<int13>
    >
  >(MPLLIBS_HERE, "test_pushing_to_empty_list");
}


