// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/look_ahead.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/digit_val.h>
#include <mpllibs/metaparse/fail.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("look_ahead");
  
  typedef
    boost::mpl::equal_to<
      int1,
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::look_ahead<mpllibs::metaparse::digit_val>,
          str_1983,
          mpllibs::metaparse::start
        >
      >::type
    >
    TestReturnsResult;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::look_ahead<mpllibs::metaparse::fail<int13> >,
        str_1983,
        mpllibs::metaparse::start
      >
    >
    TestReturnsError;

  typedef
    boost::mpl::equal<
      str_1983,
      mpllibs::metaparse::get_remaining<
        boost::mpl::apply<
          mpllibs::metaparse::look_ahead<mpllibs::metaparse::digit_val>,
          str_1983,
          mpllibs::metaparse::start
        >
      >::type
    >
    TestDoesntProcessInput;
}

MPLLIBS_ADD_TEST(suite, TestReturnsResult)
MPLLIBS_ADD_TEST(suite, TestReturnsError)
MPLLIBS_ADD_TEST(suite, TestDoesntProcessInput)


