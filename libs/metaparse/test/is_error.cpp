// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include "common.hpp"

#include <boost/mpl/not.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_is_error)
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::fail;
  
  using boost::mpl::not_;
  using boost::mpl::apply_wrap2;

  // test_not_error
  BOOST_MPL_ASSERT((not_<is_error<int13> >));

  // test_error
  BOOST_MPL_ASSERT((is_error<apply_wrap2<fail<int11>, int1, int13> >));
}

