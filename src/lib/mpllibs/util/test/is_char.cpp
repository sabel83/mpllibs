// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_char.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>

namespace
{
  typedef
    mpllibs::util::is_char<
      boost::mpl::integral_c<char, 'a'>
    >::apply<boost::mpl::integral_c<char, 'a'> >::type
    IsChar_TestSame;
  
  typedef
    mpllibs::util::is_char<
      boost::mpl::integral_c<char, 'a'>
    >::apply<boost::mpl::integral_c<char, 'b'> >::type
    IsChar_TestDifferent;
}

MPLLIBS_ADD_TEST(IsChar_TestSame)
MPLLIBS_ADD_TEST_TO_FAIL(IsChar_TestDifferent)

