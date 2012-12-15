// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  struct has_no_type {};
}

BOOST_AUTO_TEST_CASE(test_returns)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metamonad::returns;
  using boost::is_same;

  meta_require<
    is_same<has_no_type, returns<has_no_type>::type>
  >(MPLLIBS_HERE, "test_returns");
}


