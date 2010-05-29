#ifndef MPLLIBS_UTIL_IS_LETTER_H
#define MPLLIBS_UTIL_IS_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_ucase_letter.h>
#include <mpllibs/util/is_lcase_letter.h>

#include <boost/mpl/or.hpp>

namespace mpllibs
{
  namespace util
  {
    struct is_letter
    {
      template <class S>
      struct apply :
        boost::mpl::or_<
          mpllibs::util::is_lcase_letter::apply<S>,
          mpllibs::util::is_ucase_letter::apply<S>
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

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace test_mpllibs_util_is_letter
  {
    namespace
    {
      struct TestLcaseLetter :
        mpllibs::test::test<
          mpllibs::util::is_letter::apply<
            boost::mpl::integral_c<char, 'k'>
          >::type
        >
      {};

      struct TestUcaseLetter :
        mpllibs::test::test<
          mpllibs::util::is_letter::apply<
            boost::mpl::integral_c<char, 'K'>
          >::type
        >
      {};

      struct TestNonLetter :
        mpllibs::test::test_fail<
          mpllibs::util::is_letter::apply<
            boost::mpl::integral_c<char, '8'>
          >::type
        >
      {};
    }
  }
}
#endif

#endif

