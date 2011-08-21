// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/just.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>

#include <mpllibs/metatest/test.hpp>

#include "common.hpp"

#include <boost/mpl/not.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::just;
using mpllibs::metamonad::get_data;
using mpllibs::metamonad::is_nothing;

using boost::mpl::equal_to;
using boost::mpl::not_;

namespace
{
  const suite_path suite("just");
  
  typedef just<int13> just13;
  typedef just<int11> just11;
  
  typedef equal_to<get_data<just13>::type, int13> test_get_data;

  typedef equal_to<just13, just13> test_compare_with_same_data;

  typedef not_<equal_to<just13, just11> > test_compare_with_different_data;

  typedef not_<is_nothing<just13> > test_is_nothing;
}

MPLLIBS_ADD_TEST(suite, test_get_data)
MPLLIBS_ADD_TEST(suite, test_compare_with_same_data)
MPLLIBS_ADD_TEST(suite, test_compare_with_different_data)
MPLLIBS_ADD_TEST(suite, test_is_nothing)

