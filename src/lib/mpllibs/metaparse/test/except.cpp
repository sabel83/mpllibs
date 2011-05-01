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
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::except;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::fail;

using boost::mpl::apply;
using boost::mpl::equal_to;

namespace
{
  const test_suite suite("except");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);

  typedef
    is_error<apply<except<one_char, int13, test_error>, str_hello, start> >
    test_with_good;
  
  typedef
    equal_to<
      get_result<
        apply<except<fail<test_error>, int13, test_error>, str_hello, start>
      >::type,
      int13
    >
    test_with_bad;
}

MPLLIBS_ADD_TEST(suite, test_with_good)
MPLLIBS_ADD_TEST(suite, test_with_bad)


