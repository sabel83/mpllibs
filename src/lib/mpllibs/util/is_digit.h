#ifndef MPLLIBS_UTIL_IS_DIGIT_H
#define MPLLIBS_UTIL_IS_DIGIT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/in_range.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace util
  {
    typedef
      mpllibs::util::in_range<
        boost::mpl::integral_c<char, '0'>,
        boost::mpl::integral_c<char, '9'>
      >
      is_digit;
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_UTIL_SELF_TEST

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

namespace mpllibs
{
  namespace test_mpllibs_util_is_digit
  {
    namespace
    {
      struct TestDigit :
        mpllibs::test::test<
          mpllibs::util::is_digit::apply<
            boost::mpl::integral_c<char, '7'>
          >::type
        >
      {};

      struct TestNonDigit :
        mpllibs::test::test_fail<
          mpllibs::util::is_digit::apply<
            boost::mpl::integral_c<char, 'a'>
          >::type
        >
      {};
    }
  }
}
#endif

#endif

