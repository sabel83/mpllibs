// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/sequence.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::sequence<lit_h, lit_e>::apply<str_hello>::type::first,
      mpllibs::util::pair<char_h, char_e>
    >
    Sequence_TestTwoChars;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::sequence<lit_x, lit_e>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Sequence_TestFirstFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::sequence<lit_h, lit_x>::apply<str_hello>::type,
      mpllibs::parser::nothing
    >
    Sequence_TestSecondFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::sequence<lit_h, lit_e>::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Sequence_TestEmptyInput;
}

MPLLIBS_ADD_TEST(Sequence_TestTwoChars)
MPLLIBS_ADD_TEST(Sequence_TestFirstFails)
MPLLIBS_ADD_TEST(Sequence_TestSecondFails)
MPLLIBS_ADD_TEST(Sequence_TestEmptyInput)


