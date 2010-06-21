// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_lcase_letter.h>

#include <mpllibs/test/test.h>

namespace
{
  typedef
    mpllibs::util::is_lcase_letter::apply<boost::mpl::integral_c<char, 'k'> >
    IsLcaseLetter_TestLetter;
  
  typedef
    mpllibs::util::is_lcase_letter::apply<boost::mpl::integral_c<char, 'K'> >
    IsLcaseLetter_TestNonLetter;
}

MPLLIBS_ADD_TEST(IsLcaseLetter_TestLetter)
MPLLIBS_ADD_TEST_TO_FAIL(IsLcaseLetter_TestNonLetter)

