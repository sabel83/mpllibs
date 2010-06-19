// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_char.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

#include <boost/mpl/integral_c.hpp>

namespace
{
  struct TestSame :
    mpllibs::test::test<
      mpllibs::util::is_char<
        boost::mpl::integral_c<char, 'a'>
      >::apply<boost::mpl::integral_c<char, 'a'> >::type
    >
  {};

  struct TestDifferent :
    mpllibs::test::test_fail<
      mpllibs::util::is_char<
        boost::mpl::integral_c<char, 'a'>
      >::apply<boost::mpl::integral_c<char, 'b'> >::type
    >
  {};
}


