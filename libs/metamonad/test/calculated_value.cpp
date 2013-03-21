// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/calculated_value.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/assert.hpp> 

#include <boost/type_traits.hpp>

#include <string>

using mpllibs::metamonad::calculated_value;
using mpllibs::metamonad::tmp_tag;

namespace
{
  struct t : tmp_tag<t> {};

  struct foo : calculated_value<foo, std::string, t>
  {
    static std::string get_value() { return "foo bar"; }
  };
}

BOOST_AUTO_TEST_CASE(test_calculated_value)
{
  using boost::is_same;

  BOOST_CHECK_EQUAL("foo bar", foo::value);

  BOOST_MPL_ASSERT((is_same<foo::tag, t>));
}



