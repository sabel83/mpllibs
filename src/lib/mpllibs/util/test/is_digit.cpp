// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_digit.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

namespace
{
  struct TestDigit :
    mpllibs::test::test<
      mpllibs::util::is_digit::apply<boost::mpl::integral_c<char, '7'> >::type
    >
  {};

  struct TestNonDigit :
    mpllibs::test::test_fail<
      mpllibs::util::is_digit::apply<boost::mpl::integral_c<char, 'a'> >::type
    >
  {};
}

