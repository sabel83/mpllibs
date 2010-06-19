// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_whitespace.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

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


