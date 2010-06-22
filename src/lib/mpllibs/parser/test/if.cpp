// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/if.h>
#include <mpllibs/parser/digit.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::if_<
        mpllibs::parser::digit,
        int11,
        int13
      >::apply<str_1>::type::first,
      int11
    >
    If_TestTrue;
    
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::if_<
        mpllibs::parser::digit,
        int11,
        int13
      >::apply<str_a>::type::first,
      int13
    >
    If_TestFalse;
}

MPLLIBS_ADD_TEST(If_TestTrue)
MPLLIBS_ADD_TEST(If_TestFalse)

