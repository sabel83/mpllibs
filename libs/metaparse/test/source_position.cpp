// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/next_char.hpp>
#include <mpllibs/metaparse/next_line.hpp>
#include <mpllibs/metaparse/get_prev_char.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::get_line;
using mpllibs::metaparse::get_col;
using mpllibs::metaparse::source_position;
using mpllibs::metaparse::get_prev_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::next_char;
using mpllibs::metaparse::next_line;

using boost::mpl::equal_to;

namespace
{
  const suite_path suite("source_position");
  
  typedef source_position<int11, int13, int1> sp;
  typedef next_char<start, char_0> next0;
  
  
  typedef equal_to<int11, get_line<sp>::type> test_get_line;

  typedef equal_to<int13, get_col<sp>::type> test_get_col;
  
  typedef equal_to<int1, get_prev_char<sp>::type> test_get_prev_char;

  typedef equal_to<int1, get_line<start>::type> test_line_of_start;

  typedef equal_to<int1, get_col<start>::type> test_col_of_start;

  typedef equal_to<int2, get_col<next0>::type> test_next_chars_char;

  typedef equal_to<int1, get_line<next0>::type> test_next_chars_line;

  typedef
    equal_to<int1, get_col<next_line<next0, char_0> >::type>
    test_next_lines_char;

  typedef
    equal_to<int2, get_line<next_line<start, char_0> >::type>
    test_next_lines_line;

  typedef
    equal_to<char_1, get_prev_char< next_char<start, char_1> >::type>
    test_next_chars_prev_char;

  typedef
    equal_to<char_1, get_prev_char<next_line<start, char_1> >::type>
    test_next_lines_prev_char;
}

MPLLIBS_ADD_TEST(suite, test_get_line)
MPLLIBS_ADD_TEST(suite, test_get_col)
MPLLIBS_ADD_TEST(suite, test_get_prev_char)

MPLLIBS_ADD_TEST(suite, test_line_of_start)
MPLLIBS_ADD_TEST(suite, test_col_of_start)

MPLLIBS_ADD_TEST(suite, test_next_chars_char)
MPLLIBS_ADD_TEST(suite, test_next_chars_line)
MPLLIBS_ADD_TEST(suite, test_next_lines_char)
MPLLIBS_ADD_TEST(suite, test_next_lines_line)

MPLLIBS_ADD_TEST(suite, test_next_chars_prev_char)
MPLLIBS_ADD_TEST(suite, test_next_lines_prev_char)


