#ifndef MPLLIBS_UTIL_IS_CHAR_H
#define MPLLIBS_UTIL_IS_CHAR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace util
  {
    template <class c>
    struct is_char
    {
      template <class s>
      struct apply : boost::mpl::equal_to<c, s> {};
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
  namespace test_mpllibs_util_is_char
  {
    namespace
    {
      struct TestSame :
        mpllibs::test::test<
          mpllibs::util::is_char<
            boost::mpl::integral_c<char, 'a'>
          >::apply<boost::mpl::integral_c<char, 'a'> >::type
        >
      {};

      struct TestDifferent :
        mpllibs::test::test_fail<
          mpllibs::util::is_char<
            boost::mpl::integral_c<char, 'a'>
          >::apply<boost::mpl::integral_c<char, 'b'> >::type
        >
      {};
    }
  }
}
#endif

#endif

