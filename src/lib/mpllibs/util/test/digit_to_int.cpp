// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/digit_to_int.h>

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("digit_to_int");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::util::digit_to_int,
        boost::mpl::integral_c<char, '0'>
      >::type,
      boost::mpl::int_<0>
    >
    Test0;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::util::digit_to_int,
        boost::mpl::integral_c<char, '9'>
      >::type,
      boost::mpl::int_<9>
    >
    Test9;
}

MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test9)


