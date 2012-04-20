// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/mpl/plus.hpp>

#include <boost/mpl/equal_to.hpp>

#include <boost/type_traits/is_same.hpp>

using mpllibs::metatest::suite_path;

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

namespace
{
  const suite_path suite("example_failure");

  typedef bad<int> test_no_type;

  typedef bad2<int> test_no_type_value;

  typedef false_ test_fail;
  
  typedef
    equal_to<int_<11>, plus<int_<13>, int_<27> >::type>
    test_fail_with_to_equal;

  typedef is_same<int, double> test_fail_with_is_same;

  typedef not_<and_<or_<true_, false_>, true_> > test_fail_complex_expression;
}

MPLLIBS_ADD_TEST(suite, test_no_type)
MPLLIBS_ADD_TEST(suite, test_no_type_value)
MPLLIBS_ADD_TEST(suite, test_fail)
MPLLIBS_ADD_TEST(suite, test_fail_with_to_equal)
MPLLIBS_ADD_TEST(suite, test_fail_with_is_same)
MPLLIBS_ADD_TEST(suite, test_fail_complex_expression)


