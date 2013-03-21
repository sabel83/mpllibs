// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/unless_error.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  using boost::mpl::apply_wrap2;
  using mpllibs::metaparse::fail;

  typedef apply_wrap2<fail<int1>, int11, int2> err;
}

BOOST_AUTO_TEST_CASE(test_util_unless_error)
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::unless_error;
  
  using boost::mpl::equal_to;

  // test_error
  BOOST_MPL_ASSERT((is_error<unless_error<err, int13> >));

  // test_not_error
  BOOST_MPL_ASSERT((equal_to<int13, unless_error<int11, int13>::type>));
}


