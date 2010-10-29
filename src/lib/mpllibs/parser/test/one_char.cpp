// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_char.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("one_char");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::one_char,
        str_hello
      >::type::first,
      char_h
    >
    TestOnceCharForNonEmptyString;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::one_char,
        boost::mpl::apply<mpllibs::parser::one_char, str_hello>::type::second
      >::type::first,
      char_e
    >
    TestOnceCharForNonEmptyStringSecond;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::parser::one_char, str_>::type,
      mpllibs::parser::nothing
    >
    TestOnceCharForEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestOnceCharForNonEmptyString)
MPLLIBS_ADD_TEST(suite, TestOnceCharForNonEmptyStringSecond)
MPLLIBS_ADD_TEST(suite, TestOnceCharForEmptyString)


