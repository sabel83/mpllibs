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
#include <mpllibs/metaparse/iterate_c.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_remaining;
using mpllibs::metaparse::get_position;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::iterate_c;
using mpllibs::metaparse::get_line;

using boost::mpl::list_c;
using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const test_suite suite("one_char");

  typedef list_c<char, 'a','\n','b'> unix_multi_line_text;
  typedef list_c<char, 'a','\r','\n','b'> dos_multi_line_text;
  typedef list_c<char, 'a','\r','b'> mac_multi_line_text;

  typedef apply<one_char, str_hello, start> parse_first_char;

  typedef
    equal_to<get_result<parse_first_char>::type, char_h>
    test_one_char_for_non_empty_string;

  typedef
    equal_to<
      get_result<
        apply<
          one_char,
          get_remaining<parse_first_char>::type,
          get_position<parse_first_char>::type
        >
      >::type,
      char_e
    >
    test_one_char_for_non_empty_string_second;

  typedef
    is_error<
      apply<one_char, str_, start>
    >
    test_one_char_for_empty_string;
  
  typedef
    equal_to<
      int2,
      get_line<
        get_position<
          apply<iterate_c<one_char, 2>, unix_multi_line_text, start>
        >
      >
    >
    test_unix_multi_line_text;

  typedef
    equal_to<
      int2,
      get_line<
        get_position<
          apply<iterate_c<one_char, 3>, dos_multi_line_text, start>
        >
      >
    >
    test_dos_multi_line_text;

  typedef
    equal_to<
      int2,
      get_line<
        get_position<
          apply<iterate_c<one_char, 2>, mac_multi_line_text, start>
        >
      >
    >
    test_mac_multi_line_text;
}

MPLLIBS_ADD_TEST(suite, test_one_char_for_non_empty_string)
MPLLIBS_ADD_TEST(suite, test_one_char_for_non_empty_string_second)
MPLLIBS_ADD_TEST(suite, test_one_char_for_empty_string)

MPLLIBS_ADD_TEST(suite, test_unix_multi_line_text)
MPLLIBS_ADD_TEST(suite, test_dos_multi_line_text)
MPLLIBS_ADD_TEST(suite, test_mac_multi_line_text)

