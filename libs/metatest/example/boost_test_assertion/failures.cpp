// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <mpllibs/metatest/boost_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/mpl/plus.hpp>

#include <boost/mpl/equal_to.hpp>

#include <boost/type_traits/is_same.hpp>

using mpllibs::metatest::meta_check;

using boost::mpl::true_;
using boost::mpl::false_;
using boost::mpl::equal_to;
using boost::mpl::int_;
using boost::mpl::plus;
using boost::mpl::not_;
using boost::mpl::and_;
using boost::mpl::or_;

using boost::is_same;

// Bad metafunction: no "type"
template <class T>
struct bad {};

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, bad, "bad")

// Bad metafunction for a test case: no "type::value"
template <class T>
struct bad2
{
  struct type {};
};

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, bad2, "bad2")

BOOST_AUTO_TEST_CASE(example_failure)
{
  meta_check<bad<int> >(MPLLIBS_HERE, "test_no_type");

  meta_check<bad2<int> >(MPLLIBS_HERE, "test_no_type_value");

  meta_check<false_>(MPLLIBS_HERE);
  
  meta_check<equal_to<int_<1>, plus<int_<3>, int_<2> >::type> >(MPLLIBS_HERE);

  meta_check<is_same<int, double> >(MPLLIBS_HERE);

  meta_check<not_<and_<or_<true_, false_>, true_> > >(MPLLIBS_HERE);
}


