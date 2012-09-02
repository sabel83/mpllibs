// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/left.hpp>
#include <mpllibs/metamonad/is_right.hpp>
#include <mpllibs/metamonad/is_left.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/int.hpp>

BOOST_AUTO_TEST_CASE(test_left)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::left;
  using mpllibs::metamonad::get_data;
  using mpllibs::metamonad::is_left;
  using mpllibs::metamonad::is_right;
  
  using boost::mpl::equal_to;
  using boost::mpl::not_;
  using boost::mpl::int_;

  typedef int_<13> int13;
  typedef int_<11> int11;
  
  typedef left<int13> left13;
  typedef left<int11> left11;
  
  meta_require<
    equal_to<get_data<left13>::type, int13>
  >(MPLLIBS_HERE, "test_get_data");

  meta_require<
    equal_to<left13, left13>
  >(MPLLIBS_HERE, "test_compare_with_same_data");

  meta_require<
    not_<equal_to<left13, left11> >
  >(MPLLIBS_HERE, "test_compare_with_different_data");

  meta_require<is_left<left13> >(MPLLIBS_HERE, "test_is_left");

  meta_require<not_<is_right<left13> > >(MPLLIBS_HERE, "test_is_right");
}

