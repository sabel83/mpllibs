// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_char.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_char::apply<str_hello>::type::first,
      char_h
    >
    OneChar_TestOnceCharForNonEmptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_char::apply<
        mpllibs::parser::one_char::apply<str_hello>::type::second
      >::type::first,
      char_e
    >
    OneChar_TestOnceCharForNonEmptyStringSecond;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::one_char::apply<str_>::type,
      mpllibs::parser::nothing
    >
    OneChar_TestOnceCharForEmptyString;
}

MPLLIBS_ADD_TEST(OneChar_TestOnceCharForNonEmptyString)
MPLLIBS_ADD_TEST(OneChar_TestOnceCharForNonEmptyStringSecond)
MPLLIBS_ADD_TEST(OneChar_TestOnceCharForEmptyString)


