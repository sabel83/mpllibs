// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_whitespace.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("is_whitespace");

  typedef
    boost::mpl::apply<
      mpllibs::util::is_whitespace,
      boost::mpl::integral_c<char, ' '>
    >
    TestSpace;
  
  typedef
    boost::mpl::apply<
      mpllibs::util::is_whitespace,
      boost::mpl::integral_c<char, '\t'>
    >
    TestTab;
  
  typedef
    boost::mpl::apply<
      mpllibs::util::is_whitespace,
      boost::mpl::integral_c<char, 'a'>
    >
    TestNonWhitespace;
}

MPLLIBS_ADD_TEST(suite, TestSpace)
MPLLIBS_ADD_TEST(suite, TestTab)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonWhitespace)


