#ifndef MPLLIBS_UTIL_IS_WHITESPACE_H
#define MPLLIBS_UTIL_IS_WHITESPACE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/or.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace util
  {
    struct is_whitespace
    {
      template <class c>
      struct apply :
        boost::mpl::or_<
          boost::mpl::equal_to<c, boost::mpl::integral_c<char, ' '> >,
          boost::mpl::equal_to<c, boost::mpl::integral_c<char, '\r'> >,
          boost::mpl::equal_to<c, boost::mpl::integral_c<char, '\n'> >,
          boost::mpl::equal_to<c, boost::mpl::integral_c<char, '\t'> >
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

namespace mpllibs
{
  namespace test_mpllibs_util_is_whitespace
  {
    namespace
    {
      struct TestSpace :
        mpllibs::test::test<
          mpllibs::util::is_whitespace::apply<
            boost::mpl::integral_c<char, ' '>
          >::type
        >
      {};

      struct TestTab :
        mpllibs::test::test<
          mpllibs::util::is_whitespace::apply<
            boost::mpl::integral_c<char, '\t'>
          >::type
        >
      {};

      struct TestNonWhitespace :
        mpllibs::test::test_fail<
          mpllibs::util::is_whitespace::apply<
            boost::mpl::integral_c<char, 'a'>
          >::type
        >
      {};
    }
  }
}
#endif

#endif

