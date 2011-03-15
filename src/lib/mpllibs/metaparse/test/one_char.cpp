// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_char.h>
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
  const mpllibs::metatest::TestSuite suite("one_char");

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_char,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestOnceCharForNonEmptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_char,
          mpllibs::metaparse::get_remaining<
            boost::mpl::apply<
              mpllibs::metaparse::one_char,
              str_hello,
              mpllibs::metaparse::start
            >
          >::type,
          mpllibs::metaparse::get_position<
            boost::mpl::apply<
              mpllibs::metaparse::one_char,
              str_hello,
              mpllibs::metaparse::start
            >
          >::type
        >
      >::type,
      char_e
    >
    TestOnceCharForNonEmptyStringSecond;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_char,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestOnceCharForEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestOnceCharForNonEmptyString)
MPLLIBS_ADD_TEST(suite, TestOnceCharForNonEmptyStringSecond)
MPLLIBS_ADD_TEST(suite, TestOnceCharForEmptyString)


