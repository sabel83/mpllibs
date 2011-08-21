// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/right.hpp>
#include <mpllibs/metamonad/is_left.hpp>
#include <mpllibs/metamonad/is_right.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/int.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::right;
using mpllibs::metamonad::get_data;
using mpllibs::metamonad::is_left;
using mpllibs::metamonad::is_right;

using boost::mpl::equal_to;
using boost::mpl::not_;
using boost::mpl::int_;

namespace
{
  const suite_path suite("right");
  
  typedef int_<13> int13;
  typedef int_<11> int11;

  typedef right<int13> right13;
  typedef right<int11> right11;
  
  typedef equal_to<get_data<right13>::type, int13> test_get_data;

  typedef equal_to<right13, right13> test_compare_with_same_data;

  typedef not_<equal_to<right13, right11> > test_compare_with_different_data;

  typedef not_<is_left<right13> > test_is_left;

  typedef is_right<right13> test_is_right;
}

MPLLIBS_ADD_TEST(suite, test_get_data)
MPLLIBS_ADD_TEST(suite, test_compare_with_same_data)
MPLLIBS_ADD_TEST(suite, test_compare_with_different_data)
MPLLIBS_ADD_TEST(suite, test_is_left)
MPLLIBS_ADD_TEST(suite, test_is_right)


