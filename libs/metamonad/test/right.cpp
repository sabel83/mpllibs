// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/right.hpp>
#include <mpllibs/metamonad/is_left.hpp>
#include <mpllibs/metamonad/is_right.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/int.hpp>

BOOST_AUTO_TEST_CASE(test_right)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::right;
  using mpllibs::metamonad::get_data;
  using mpllibs::metamonad::is_left;
  using mpllibs::metamonad::is_right;
  
  using boost::mpl::equal_to;
  using boost::mpl::not_;
  using boost::mpl::int_;

  typedef int_<13> int13;
  typedef int_<11> int11;

  typedef right<int13> right13;
  typedef right<int11> right11;
  
  meta_require<
    equal_to<get_data<right13>::type, int13>
  >(MPLLIBS_HERE, "test_get_data");

  meta_require<
    equal_to<right13, right13>
  >(MPLLIBS_HERE, "test_compare_with_same_data");

  meta_require<
    not_<equal_to<right13, right11> >
  >(MPLLIBS_HERE, "test_compare_with_different_data");

  meta_require<not_<is_left<right13> > >(MPLLIBS_HERE, "test_is_left");

  meta_require<is_right<right13> >(MPLLIBS_HERE, "test_is_right");
}


