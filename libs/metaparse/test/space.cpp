// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

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

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  using boost::mpl::list_c;

  typedef list_c<char, '\t', 'e', 'l', 'l', 'o'> str_with_t;
  typedef list_c<char, '\n', 'e', 'l', 'l', 'o'> str_with_n;
  typedef list_c<char, '\r', 'e', 'l', 'l', 'o'> str_with_r;
}

BOOST_AUTO_TEST_CASE(test_space)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::space;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  using boost::mpl::char_;

  meta_require<has_type<space> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<apply_wrap2<space, str_hello, start> >
  >(MPLLIBS_HERE, "test_with_text");

  meta_require<
    equal_to<
      get_result<apply_wrap2<space, str__ello, start> >::type,
      char_<' '>
    >
  >(MPLLIBS_HERE, "test_with_space");

  meta_require<
    equal_to<
      get_result<apply_wrap2<space, str_with_t, start> >::type,
      char_<'\t'>
    >
  >(MPLLIBS_HERE, "test_with_tab");

  meta_require<
    equal_to<
      get_result<apply_wrap2<space, str_with_n, start> >::type,
      char_<'\n'>
    >
  >(MPLLIBS_HERE, "test_with_line_feed");

  meta_require<
    equal_to<
      get_result<apply_wrap2<space, str_with_r, start> >::type,
      char_<'\r'>
    >
  >(MPLLIBS_HERE, "test_with_c_return");

  meta_require<
    is_error<apply_wrap2<space, str_, start> >
  >(MPLLIBS_HERE, "test_with_empty_string");
}


