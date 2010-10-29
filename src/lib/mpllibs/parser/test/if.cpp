// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/if.h>
#include <mpllibs/parser/digit.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("if");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::if_<mpllibs::parser::digit, int11, int13>,
        str_1
      >::type::first,
      int11
    >
    TestTrue;
    
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::if_<mpllibs::parser::digit, int11, int13>,
        str_a
      >::type::first,
      int13
    >
    TestFalse;
}

MPLLIBS_ADD_TEST(suite, TestTrue)
MPLLIBS_ADD_TEST(suite, TestFalse)

