// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/except.h>
#include <mpllibs/metaparse/one_char.h>
#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include <mpllibs/metaparse/util/define_data.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("except");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::except<
          mpllibs::metaparse::one_char,
          int13,
          test_error
        >,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestWithGood;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::except<
            mpllibs::metaparse::fail<test_error>,
            int13,
            test_error
          >,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      int13
    >
    TestWithBad;
}

MPLLIBS_ADD_TEST(suite, TestWithGood)
MPLLIBS_ADD_TEST(suite, TestWithBad)


