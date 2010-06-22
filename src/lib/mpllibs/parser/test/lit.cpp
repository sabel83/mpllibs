// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<lit_h::apply<str_hello>::type::first, char_h>
    Lit_TestAccept;

  typedef
    boost::mpl::equal_to<
      lit_h::apply<str_bello>::type,
      mpllibs::parser::nothing
    >
    Lit_TestReject;

  typedef
    boost::mpl::equal_to<lit_h::apply<str_>::type, mpllibs::parser::nothing>
    Lit_TestWithEmptyString;

  typedef
    boost::mpl::equal_to<
      lit_e::apply<lit_h::apply<str_hello>::type::second>::type::first,
      char_e
    >
    Lit_TestRemainingString;
}

MPLLIBS_ADD_TEST(Lit_TestAccept)
MPLLIBS_ADD_TEST(Lit_TestReject)
MPLLIBS_ADD_TEST(Lit_TestWithEmptyString)
MPLLIBS_ADD_TEST(Lit_TestRemainingString)


