// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/next_char.hpp>
#include <mpllibs/metaparse/next_line.hpp>
#include <mpllibs/metaparse/get_prev_char.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  using mpllibs::metaparse::source_position;
  using mpllibs::metaparse::next_char;
  using mpllibs::metaparse::start;

  typedef source_position<int11, int13, int1> sp;
  typedef next_char<start, char_0> next0;
 }

BOOST_AUTO_TEST_CASE(test_source_position)
{
  using mpllibs::metaparse::get_line;
  using mpllibs::metaparse::get_col;
  using mpllibs::metaparse::get_prev_char;
  using mpllibs::metaparse::next_line;
  
  using boost::mpl::equal_to;
  
  // test_get_line
  BOOST_MPL_ASSERT((equal_to<int11, get_line<sp>::type>));

  // test_get_col
  BOOST_MPL_ASSERT((equal_to<int13, get_col<sp>::type>));
  
  // test_get_prev_char
  BOOST_MPL_ASSERT((equal_to<int1, get_prev_char<sp>::type>));

  // test_line_of_start
  BOOST_MPL_ASSERT((equal_to<int1, get_line<start>::type>));

  // test_col_of_start
  BOOST_MPL_ASSERT((equal_to<int1, get_col<start>::type>));

  // test_next_chars_char
  BOOST_MPL_ASSERT((equal_to<int2, get_col<next0>::type>));

  // test_next_chars_line
  BOOST_MPL_ASSERT((equal_to<int1, get_line<next0>::type>));

  // test_next_lines_char
  BOOST_MPL_ASSERT((
    equal_to<int1, get_col<next_line<next0, char_0> >::type>
  ));

  // test_next_lines_line
  BOOST_MPL_ASSERT((
    equal_to<int2, get_line<next_line<start, char_0> >::type>
  ));

  // test_next_chars_prev_char
  BOOST_MPL_ASSERT((
    equal_to<char_1, get_prev_char< next_char<start, char_1> >::type>
  ));

  // test_next_lines_prev_char
  BOOST_MPL_ASSERT((
    equal_to<char_1, get_prev_char<next_line<start, char_1> >::type>
  ));
}

