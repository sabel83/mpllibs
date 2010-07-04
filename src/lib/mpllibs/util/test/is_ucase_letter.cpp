// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_ucase_letter.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

namespace
{
  const mpllibs::test::TestSuite suite("is_ucase_letter");

  typedef
    mpllibs::util::is_ucase_letter::apply<boost::mpl::integral_c<char, 'K'> >
    TestLetter;
  
  typedef
    mpllibs::util::is_ucase_letter::apply<boost::mpl::integral_c<char, 'k'> >
    TestNonLetter;
}

MPLLIBS_ADD_TEST(suite, TestLetter)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonLetter)



