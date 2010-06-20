// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_letter.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>

namespace
{
  typedef
    mpllibs::util::is_letter::apply<
      boost::mpl::integral_c<char, 'k'>
    >::type
    IsLetter_TestLcaseLetter;
  
  typedef
    mpllibs::util::is_letter::apply<
      boost::mpl::integral_c<char, 'K'>
    >::type
    IsLetter_TestUcaseLetter;
    
  typedef
    mpllibs::util::is_letter::apply<
      boost::mpl::integral_c<char, '8'>
    >::type
    IsLetter_TestNonLetter;
}

MPLLIBS_ADD_TEST(IsLetter_TestLcaseLetter)
MPLLIBS_ADD_TEST(IsLetter_TestUcaseLetter)
MPLLIBS_ADD_TEST_TO_FAIL(IsLetter_TestNonLetter)



