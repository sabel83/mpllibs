// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/just.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/not.hpp>

BOOST_AUTO_TEST_CASE(test_just)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::just;
  using mpllibs::metamonad::get_data;
  using mpllibs::metamonad::is_nothing;
  
  using boost::mpl::equal_to;
  using boost::mpl::not_;

  typedef just<int13> just13;
  typedef just<int11> just11;
  
  meta_require<
    equal_to<get_data<just13>::type, int13>
  >(MPLLIBS_HERE, "test_get_data");

  meta_require<
    equal_to<just13, just13>
  >(MPLLIBS_HERE, "test_compare_with_same_data");

  meta_require<
    not_<equal_to<just13, just11> >
  >(MPLLIBS_HERE, "test_compare_with_different_data");

  meta_require<not_<is_nothing<just13> > >(MPLLIBS_HERE, "test_is_nothing");
}

