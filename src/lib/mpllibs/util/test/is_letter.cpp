// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_letter.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("is_letter");

  typedef
    boost::mpl::apply<
      mpllibs::util::is_letter,
      boost::mpl::integral_c<char, 'k'>
    >
    TestLcaseLetter;
  
  typedef
    boost::mpl::apply<
      mpllibs::util::is_letter,
      boost::mpl::integral_c<char, 'K'>
    >
    TestUcaseLetter;
    
  typedef
    boost::mpl::apply<
      mpllibs::util::is_letter,
      boost::mpl::integral_c<char, '8'>
    >
    TestNonLetter;
}

MPLLIBS_ADD_TEST(suite, TestLcaseLetter)
MPLLIBS_ADD_TEST(suite, TestUcaseLetter)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonLetter)



