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
#include <mpllibs/metamonad/name.hpp>

#include <mpllibs/metamonad/mzero.hpp>
#include <mpllibs/metamonad/mplus.hpp>

#include <mpllibs/metamonad/mempty.hpp>
#include <mpllibs/metamonad/mappend.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  template <class T>
  struct get_maybe_data;

  template <class T>
  struct get_maybe_data<mpllibs::metamonad::just<T> > : mpllibs::metamonad::returns<T> {};
}

BOOST_AUTO_TEST_CASE(test_maybe)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::just;
  using mpllibs::metamonad::nothing;
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::maybe_tag;
  using mpllibs::metamonad::fail;

  using mpllibs::metamonad::mplus;
  using mpllibs::metamonad::mzero;

  using mpllibs::metamonad::mempty;
  using mpllibs::metamonad::mappend;
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::lambda_c;
  
  using boost::mpl::equal_to;
  using boost::mpl::equal;
  using boost::mpl::not_;
  using boost::mpl::plus;
  using boost::mpl::_1;
  using boost::mpl::list_c;

  using namespace mpllibs::metamonad::name;

  typedef just<int13> just13;
  typedef just<int11> just11;

  typedef int11::tag int_tag;
  typedef maybe_tag<int_tag> mt;
  
  typedef list_c<char, 'h', 'e', 'l', 'l', 'o'> s_hello;
  
  typedef lambda_c<n, just<plus<n, int2> > > maybe_add_2;
  
  meta_require<
    equal_to<return_<mt, int13>, just13>
  >(MPLLIBS_HERE, "test_return");

  meta_require<
    equal_to<bind<mt, just11, maybe_add_2>::type, just13>
  >(MPLLIBS_HERE, "test_bind_with_just");

  meta_require<
    equal_to<bind<mt, nothing, maybe_add_2>::type, nothing>
  >(MPLLIBS_HERE, "test_bind_with_nothing");

  meta_require<
    equal_to<bind<mt, fail<mt, s_hello>, maybe_add_2>::type, nothing>
  >(MPLLIBS_HERE, "test_fail");

  /*
    monad_plus
  */

  typedef mzero<mt>::type zero;

  meta_require<equal_to<zero, nothing> >(MPLLIBS_HERE, "test mzero");

  meta_require<
    equal_to<zero, mplus<mt, zero, zero>::type>
  >(MPLLIBS_HERE, "test mzero + mzero");

  meta_require<
    equal_to<just13, mplus<mt, zero, just13>::type>
  >(MPLLIBS_HERE, "test mzero + x");

  meta_require<
    equal_to<just13, mplus<mt, just13, zero>::type>
  >(MPLLIBS_HERE, "test x + mzero");

  meta_require<
    equal_to<just13, mplus<mt, just13, just11>::type>
  >(MPLLIBS_HERE, "test x + y");

  /*
    monoid
  */

  typedef maybe_tag<list_tag> mlt;

  typedef mempty<mlt>::type empty_val;

  meta_require<equal_to<nothing, empty_val> >(MPLLIBS_HERE, "test mempty");

  meta_require<
    equal_to<empty_val, mappend<mlt, empty_val, empty_val>::type>
  >(MPLLIBS_HERE, "test mempty + mempty");

  meta_require<
    equal<
      list_c<int, 13>,
      get_maybe_data<mappend<mlt, just<list_c<int, 13> >, empty_val>::type>::type
    >
  >(MPLLIBS_HERE, "test x + mempty");

  meta_require<
    equal<
      list_c<int, 13>,
      get_maybe_data<mappend<mlt, empty_val, just<list_c<int, 13> > >::type>::type
    >
  >(MPLLIBS_HERE, "test mempty + x");

  meta_require<
    equal<
      list_c<int, 11, 13>,
      get_maybe_data<
        mappend<mlt, just<list_c<int, 11> >, just<list_c<int, 13> > >::type
      >::type
    >
  >(MPLLIBS_HERE, "test x + y");
}


