// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_letter.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

#include <boost/mpl/integral_c.hpp>

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

