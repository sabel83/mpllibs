// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

#include <boost/mpl/plus.hpp>

#include <boost/mpl/equal_to.hpp>

#include <boost/type_traits/is_same.hpp>

// Bad metafunction: no "type"
template <class t>
struct bad {};

// Bad metafunction for a test case: no "type::value"
template <class t>
struct bad2
{
  struct type {};
};

namespace
{
  const mpllibs::metatest::TestSuite suite("example_failure");

  typedef bad<int> TestNoType;

  typedef bad2<int> TestNoTypeValue;

  typedef boost::mpl::false_ TestFail;
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::int_<11>,
      boost::mpl::plus<boost::mpl::int_<13>, boost::mpl::int_<27> >
    >
    TestFailWithToEqual;

  typedef boost::is_same<int, double> TestFailWithIsSame;

  typedef
    boost::mpl::not_<
      boost::mpl::and_<
        boost::mpl::or_<boost::mpl::true_, boost::mpl::false_>,
        boost::mpl::true_
      >
    >
    TestFailComplexExpression;
}

MPLLIBS_ADD_TEST(suite, TestNoType)
MPLLIBS_ADD_TEST(suite, TestNoTypeValue)
MPLLIBS_ADD_TEST(suite, TestFail)
MPLLIBS_ADD_TEST(suite, TestFailWithToEqual)
MPLLIBS_ADD_TEST(suite, TestFailWithIsSame)
MPLLIBS_ADD_TEST(suite, TestFailComplexExpression)


