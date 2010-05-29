#ifndef MPLLIBS_UTIL_IS_LCASE_LETTER_H
#define MPLLIBS_UTIL_IS_LCASE_LETTER_H

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
        boost::mpl::integral_c<char, 'a'>,
        boost::mpl::integral_c<char, 'z'>
      >
      is_lcase_letter;
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
  namespace test_mpllibs_util_is_lcase_letter
  {
    namespace
    {
      struct TestLetter :
        mpllibs::test::test<
          mpllibs::util::is_lcase_letter::apply<
            boost::mpl::integral_c<char, 'k'>
          >::type
        >
      {};

      struct TestNonLetter :
        mpllibs::test::test_fail<
          mpllibs::util::is_lcase_letter::apply<
            boost::mpl::integral_c<char, 'K'>
          >::type
        >
      {};
    }
  }
}
#endif

#endif

