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
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::get_remaining;
using mpllibs::metaparse::get_position;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const test_suite suite("lit");

  typedef
    equal_to<get_result<apply<lit_h, str_hello, start> >::type, char_h>
    test_accept;

  typedef is_error<apply<lit_h, str_bello, start> > test_reject;

  typedef is_error<apply<lit_h, str_, start> > test_with_empty_string;

  typedef
    equal_to<
      get_result<
        apply<
          lit_e,
          get_remaining<apply<lit_h, str_hello, start> >::type,
          get_position<apply<lit_h, str_hello, start> >::type
        >
      >::type,
      char_e
    >
    test_remaining_string;
}

MPLLIBS_ADD_TEST(suite, test_accept)
MPLLIBS_ADD_TEST(suite, test_reject)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)
MPLLIBS_ADD_TEST(suite, test_remaining_string)


