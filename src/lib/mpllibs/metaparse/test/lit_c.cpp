// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_position.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("lit_c");

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          lit_c_h,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestAccept;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<lit_c_h, str_bello, mpllibs::metaparse::start>
    >
    TestReject;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<lit_c_h, str_, mpllibs::metaparse::start>
    >
    TestWithEmptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          lit_c_e,
          mpllibs::metaparse::get_remaining<
            boost::mpl::apply<
              lit_c_h,
              str_hello,
              mpllibs::metaparse::start
            >
          >::type,
          mpllibs::metaparse::get_position<
            boost::mpl::apply<
              lit_c_h,
              str_hello,
              mpllibs::metaparse::start
            >
          >::type
        >
      >::type,
      char_e
    >
    TestRemainingString;
}

MPLLIBS_ADD_TEST(suite, TestAccept)
MPLLIBS_ADD_TEST(suite, TestReject)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)
MPLLIBS_ADD_TEST(suite, TestRemainingString)

