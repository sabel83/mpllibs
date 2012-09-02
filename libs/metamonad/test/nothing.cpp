// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/nothing.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_nothing)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::nothing;
  using mpllibs::metamonad::is_nothing;
  
  using boost::mpl::equal_to;

  meta_require<
    equal_to<nothing, nothing>
  >(MPLLIBS_HERE, "test_compare_nothing_to_nothing");

  meta_require<is_nothing<nothing> >(MPLLIBS_HERE, "test_is_nothing");
}


