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

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>

#include <mpllibs/metatest/boost_test.hpp>
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
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_line;
  using mpllibs::metaparse::get_col;
  using mpllibs::metaparse::get_prev_char;
  using mpllibs::metaparse::next_line;
  
  using boost::mpl::equal_to;
  
  meta_require<has_type<sp> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<int11, get_line<sp>::type>
  >(MPLLIBS_HERE, "test_get_line");

  meta_require<
    equal_to<int13, get_col<sp>::type>
  >(MPLLIBS_HERE, "test_get_col");
  
  meta_require<
    equal_to<int1, get_prev_char<sp>::type>
  >(MPLLIBS_HERE, "test_get_prev_char");

  meta_require<
    equal_to<int1, get_line<start>::type>
  >(MPLLIBS_HERE, "test_line_of_start");

  meta_require<
    equal_to<int1, get_col<start>::type>
  >(MPLLIBS_HERE, "test_col_of_start");

  meta_require<
    equal_to<int2, get_col<next0>::type>
  >(MPLLIBS_HERE, "test_next_chars_char");

  meta_require<
    equal_to<int1, get_line<next0>::type>
  >(MPLLIBS_HERE, "test_next_chars_line");

  meta_require<
    equal_to<int1, get_col<next_line<next0, char_0> >::type>
  >(MPLLIBS_HERE, "test_next_lines_char");

  meta_require<
    equal_to<int2, get_line<next_line<start, char_0> >::type>
  >(MPLLIBS_HERE, "test_next_lines_line");

  meta_require<
    equal_to<char_1, get_prev_char< next_char<start, char_1> >::type>
  >(MPLLIBS_HERE, "test_next_chars_prev_char");

  meta_require<
    equal_to<char_1, get_prev_char<next_line<start, char_1> >::type>
  >(MPLLIBS_HERE, "test_next_lines_prev_char");
}

