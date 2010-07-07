// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/space.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("space");

  typedef boost::mpl::list_c<char, ' ', 'e', 'l', 'l', 'o'> str__ello;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::space, str_hello>::type,
      mpllibs::parser::nothing
    >
    TestWithText;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::space, str__ello>::type::first,
      boost::mpl::integral_c<char, ' '>
    >
    TestWithSpace;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::space, str_>::type,
      mpllibs::parser::nothing
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithSpace)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


