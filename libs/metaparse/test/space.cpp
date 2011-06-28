// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/space.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/char.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::space;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;

using boost::mpl::list_c;
using boost::mpl::apply_wrap2;
using boost::mpl::equal_to;
using boost::mpl::char_;

namespace
{
  const suite_path suite("space");

  typedef list_c<char, '\t', 'e', 'l', 'l', 'o'> str_with_t;
  typedef list_c<char, '\n', 'e', 'l', 'l', 'o'> str_with_n;
  typedef list_c<char, '\r', 'e', 'l', 'l', 'o'> str_with_r;

  typedef has_type<space> test_has_type;

  typedef is_error<apply_wrap2<space, str_hello, start> > test_with_text;

  typedef
    equal_to<
      get_result<apply_wrap2<space, str__ello, start> >::type,
      char_<' '>
    >
    test_with_space;

  typedef
    equal_to<
      get_result<apply_wrap2<space, str_with_t, start> >::type,
      char_<'\t'>
    >
    test_with_tab;

  typedef
    equal_to<
      get_result<apply_wrap2<space, str_with_n, start> >::type,
      char_<'\n'>
    >
    test_with_line_feed;

  typedef
    equal_to<
      get_result<apply_wrap2<space, str_with_r, start> >::type,
      char_<'\r'>
    >
    test_with_c_return;

  typedef is_error<apply_wrap2<space, str_, start> > test_with_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_with_text)
MPLLIBS_ADD_TEST(suite, test_with_space)
MPLLIBS_ADD_TEST(suite, test_with_tab)
MPLLIBS_ADD_TEST(suite, test_with_line_feed)
MPLLIBS_ADD_TEST(suite, test_with_c_return)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)


