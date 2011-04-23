// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/last_of.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const test_suite suite("last_of");

  typedef
    equal_to<get_result<apply<last_of<lit_h>, str_hello, start> >::type, char_h>
    test_one_char;

  typedef
    equal_to<
      get_result<apply<last_of<lit_h, lit_e>, str_hello, start> >::type,
      char_e
    >
    test_two_chars;

  typedef
    is_error<apply<last_of<lit_x, lit_e>, str_hello, start> >
    test_first_fails;

  typedef
    is_error<apply<last_of<lit_h, lit_x>, str_hello, start> >
    test_second_fails;

  typedef is_error<apply<last_of<lit_h, lit_e>, str_, start> > test_empty_input;

  typedef
    equal_to<
      get_result<apply<last_of<lit_h, lit_e, lit_l>, str_hello, start> >::type,
      char_l
    >
    test_three_chars;
}

MPLLIBS_ADD_TEST(suite, test_one_char)
MPLLIBS_ADD_TEST(suite, test_two_chars)
MPLLIBS_ADD_TEST(suite, test_first_fails)
MPLLIBS_ADD_TEST(suite, test_second_fails)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test_three_chars)


