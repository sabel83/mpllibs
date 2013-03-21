// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/has_get_value.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/assert.hpp>

using mpllibs::metamonad::tmp_value;

namespace
{
  struct with_get_value : tmp_value<with_get_value>
  {
    static int get_value() { return 13; }
  };

  struct without_get_value : tmp_value<without_get_value> {};
}

BOOST_AUTO_TEST_CASE(test_has_get_value)
{
  using mpllibs::metamonad::has_get_value;

  BOOST_MPL_ASSERT((has_get_value<with_get_value>));
  BOOST_MPL_ASSERT_NOT((has_get_value<without_get_value>));
}


