// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/has_value.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/assert.hpp>

using mpllibs::metamonad::tmp_value;

namespace
{
  struct with_const_value : tmp_value<with_const_value>
  {
    static const int value;
  };
  
  const int with_const_value::value = 13;

  struct with_enum_value : tmp_value<with_enum_value>
  {
    enum { value = 13 };
  };

  struct without_value : tmp_value<without_value> {};
}

BOOST_AUTO_TEST_CASE(test_has_value)
{
  using mpllibs::metamonad::has_value;

  BOOST_MPL_ASSERT((has_value<with_const_value>));
  BOOST_MPL_ASSERT((has_value<with_enum_value>));
  BOOST_MPL_ASSERT_NOT((has_value<without_value>));
}


