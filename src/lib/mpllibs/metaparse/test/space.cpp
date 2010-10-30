// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/space.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("space");

  typedef boost::mpl::list_c<char, ' ', 'e', 'l', 'l', 'o'> str__ello;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::space, str_hello>::type,
      mpllibs::metaparse::nothing
    >
    TestWithText;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::space, str__ello>::type::first,
      boost::mpl::integral_c<char, ' '>
    >
    TestWithSpace;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::space, str_>::type,
      mpllibs::metaparse::nothing
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithSpace)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


