// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/if.h>
#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

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
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::if_<mpllibs::metaparse::digit, int11, int13>,
          str_1,
          mpllibs::metaparse::start
        >
      >::type,
      int11
    >
    TestTrue;
    
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::if_<mpllibs::metaparse::digit, int11, int13>,
          str_a,
          mpllibs::metaparse::start
        >
      >::type,
      int13
    >
    TestFalse;
}

MPLLIBS_ADD_TEST(suite, TestTrue)
MPLLIBS_ADD_TEST(suite, TestFalse)

