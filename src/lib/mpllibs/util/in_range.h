#ifndef MPLLIBS_UTIL_IN_RANGE_H
#define MPLLIBS_UTIL_IN_RANGE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/less_equal.hpp>
#include <boost/mpl/comparison.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>

namespace mpllibs
{
  namespace util
  {
    template <class lowerBound, class upperBound>
    struct in_range
    {
      template <class item>
      struct apply :
        boost::mpl::and_<
          boost::mpl::less_equal<lowerBound, item>,
          boost::mpl::less_equal<item, upperBound>
        >
      {};
    };
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_UTIL_SELF_TEST

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace test_mpllibs_util_in_range
  {
    namespace
    {
      struct TestIntInRange :
        mpllibs::test::test<
          mpllibs::util::in_range<
            boost::mpl::int_<10>,
            boost::mpl::int_<13>
          >::apply<boost::mpl::int_<12> >::type
        >
      {};

      struct TestLowerBound :
        mpllibs::test::test<
          mpllibs::util::in_range<
            boost::mpl::int_<10>,
            boost::mpl::int_<13>
          >::apply<boost::mpl::int_<10> >::type
        >
      {};

      struct TestUpperBound :
        mpllibs::test::test<
          mpllibs::util::in_range<
            boost::mpl::int_<10>,
            boost::mpl::int_<13>
          >::apply<boost::mpl::int_<13> >::type
        >
      {};

      struct TestIntNotInRange :
        mpllibs::test::test_fail<
          mpllibs::util::in_range<
            boost::mpl::int_<10>,
            boost::mpl::int_<13>
          >::apply<boost::mpl::int_<14> >::type
        >
      {};
    }
  }
}
#endif

#endif

