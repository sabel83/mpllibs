// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/list.hpp>

#include <mpllibs/metamonad/mzero.hpp>
#include <mpllibs/metamonad/mplus.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>

BOOST_AUTO_TEST_CASE(test_list_monad_plus)
{
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::mplus;
  using mpllibs::metamonad::mzero;
  
  using boost::mpl::equal;
  using boost::mpl::list;
  
  typedef mzero<list_tag>::type zero;

  // test mzero
  BOOST_MPL_ASSERT((equal<zero, list<> >));

  // test mzero + mzero
  BOOST_MPL_ASSERT((equal<zero, mplus<list_tag, zero, zero>::type>));

  // test mzero + x
  BOOST_MPL_ASSERT((
    equal<list<int13>, mplus<list_tag, zero, list<int13> >::type>
  ));

  // test x + mzero
  BOOST_MPL_ASSERT((
    equal<list<int13>, mplus<list_tag, list<int13>, zero>::type>
  ));

  // test x + y
  BOOST_MPL_ASSERT((
    equal<list<int11, int13>, mplus<list_tag, list<int11>, list<int13> >::type>
  ));
}

