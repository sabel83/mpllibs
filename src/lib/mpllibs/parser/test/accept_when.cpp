// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/accept_when.h>
#include <mpllibs/parser/one_char.h>

#include "common.h"

#include <mpllibs/util/is_digit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_digit
      >::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    AcceptWhen_TestWithText;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_digit
      >::apply<str_1983>::type::first,
      char_1
    >
    AcceptWhen_TestWithNumber;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_digit
      >::apply<str_>::type,
      mpllibs::parser::nothing
    >
    AcceptWhen_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(AcceptWhen_TestWithText)
MPLLIBS_ADD_TEST(AcceptWhen_TestWithNumber)
MPLLIBS_ADD_TEST(AcceptWhen_TestWithEmptyString)

