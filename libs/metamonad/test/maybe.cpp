// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/fail.hpp>
#include <mpllibs/metamonad/lambda.hpp>

#include <mpllibs/metamonad/mzero.hpp>
#include <mpllibs/metamonad/mplus.hpp>

#include <mpllibs/metamonad/mempty.hpp>
#include <mpllibs/metamonad/mappend.hpp>

#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/assert.hpp>

namespace
{
  using mpllibs::metamonad::maybe_tag;
  using mpllibs::metamonad::nothing;
  using mpllibs::metamonad::just;

  using boost::mpl::equal_to;
  using boost::mpl::list_c;

  template <class T>
  struct get_maybe_data;

  template <class T>
  struct get_maybe_data<mpllibs::metamonad::just<T> > :
    mpllibs::metamonad::returns<T>
  {};

  typedef int11::tag int_tag;
  typedef maybe_tag<int_tag> mt;

  typedef just<int11> just11;
  typedef just<int13> just13;
}

BOOST_AUTO_TEST_CASE(test_maybe)
{
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::fail;

  using mpllibs::metamonad::lambda_c;
  
  using boost::mpl::plus;

  typedef list_c<char, 'h', 'e', 'l', 'l', 'o'> s_hello;
  
  typedef lambda_c<n, just<plus<n, int2> > > maybe_add_2;
  
  // test_return
  BOOST_MPL_ASSERT((equal_to<return_<mt, int13>, just13>));

  // test_bind_with_just
  BOOST_MPL_ASSERT((equal_to<bind<mt, just11, maybe_add_2>::type, just13>));

  // test_bind_with_nothing
  BOOST_MPL_ASSERT((equal_to<bind<mt, nothing, maybe_add_2>::type, nothing>));

  // test_fail
  BOOST_MPL_ASSERT((
    equal_to<bind<mt, fail<mt, s_hello>, maybe_add_2>::type, nothing>
  ));
}

BOOST_AUTO_TEST_CASE(test_maybe_monad_plus)
{
  using mpllibs::metamonad::mzero;
  using mpllibs::metamonad::mplus;

  typedef mzero<mt>::type zero;

  // test mzero
  BOOST_MPL_ASSERT((equal_to<zero, nothing>));

  // test mzero + mzero
  BOOST_MPL_ASSERT((equal_to<zero, mplus<mt, zero, zero>::type>));

  // test mzero + x
  BOOST_MPL_ASSERT((equal_to<just13, mplus<mt, zero, just13>::type>));

  // test x + mzero
  BOOST_MPL_ASSERT((equal_to<just13, mplus<mt, just13, zero>::type>));

  // test x + y
  BOOST_MPL_ASSERT((equal_to<just13, mplus<mt, just13, just11>::type>));
}

BOOST_AUTO_TEST_CASE(test_maybe_monoid)
{
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::mempty;
  using mpllibs::metamonad::mappend;

  using boost::mpl::equal;

  typedef maybe_tag<list_tag> mlt;

  typedef mempty<mlt>::type empty_val;

  // test mempty
  BOOST_MPL_ASSERT((equal_to<nothing, empty_val>));

  // test mempty + mempty
  BOOST_MPL_ASSERT((
    equal_to<empty_val, mappend<mlt, empty_val, empty_val>::type>
  ));

  // test x + mempty
  BOOST_MPL_ASSERT((
    equal<
      list_c<int, 13>,
      get_maybe_data<mappend<mlt, just<list_c<int,13> >, empty_val>::type>::type
    >
  ));

  // test mempty + x
  BOOST_MPL_ASSERT((
    equal<
      list_c<int, 13>,
      get_maybe_data<
        mappend<mlt, empty_val, just<list_c<int, 13> > >::type
      >::type
    >
  ));

  // test x + y
  BOOST_MPL_ASSERT((
    equal<
      list_c<int, 11, 13>,
      get_maybe_data<
        mappend<mlt, just<list_c<int, 11> >, just<list_c<int, 13> > >::type
      >::type
    >
  ));
}


