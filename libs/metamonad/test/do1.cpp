// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/either.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

using boost::mpl::minus;

using mpllibs::metamonad::right;

namespace
{
  MPLLIBS_LAZY_METAFUNCTION(minus_2, (A)) ((right<minus<A, int2> >));
}

BOOST_AUTO_TEST_CASE(test_do1)
{
  using mpllibs::metamonad::do_;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::set;
  using mpllibs::metamonad::do_return;

  using boost::mpl::equal_to;

  typedef boost::mpl::tag<int13>::type int_tag;
  typedef mpllibs::metamonad::either_tag<int_tag, int_tag> either;

  // test_do
  BOOST_MPL_ASSERT((
    equal_to<
      right<int11>,
      do_<either,
        syntax<set<x, do_return<int13> > >,
        syntax<minus_2<x> >
      >::type
    >
  ));

  // test_do_three_steps
  BOOST_MPL_ASSERT((
    equal_to<
      right<int9>,
      do_<either,
        syntax<set<x, do_return<int13> > >,
        syntax<set<y, minus_2<x> > >,
        syntax<minus_2<y> >
      >::type
    >
  ));

  // test_do_two_calls
  BOOST_MPL_ASSERT((
    equal_to<
      right<int9>,
      do_<either,
        syntax<set<x, do_return<int13> > >,
        syntax<set<y, minus_2<x> > >,
        syntax<minus_2<x> >,
        syntax<minus_2<y> >
      >::type
    >
  ));

  // test_do_two_returns
  BOOST_MPL_ASSERT((
    equal_to<
      right<int13>,
      do_<either,
        syntax<do_return<int11> >,
        syntax<do_return<int13> >
      >::type
    >
  ));

  // test_nested_do_with_return
  BOOST_MPL_ASSERT((
    equal_to<
      right<right<int13> >,
      do_<either,
        syntax<
          do_return<
            do_<either,
              syntax<do_return<int13> >
            >
          >
        >
      >::type
    >
  ));
}




