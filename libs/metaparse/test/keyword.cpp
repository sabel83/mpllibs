// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  using mpllibs::metaparse::keyword;

  using boost::mpl::list_c;

  typedef
    list_c<char, 'h','e','l','l','o',' ','w','o','r','l','d'>
    str_hello_world;
    
  typedef list_c<char, 'h','e','l','l','x'> str_hellx;
  typedef list_c<char, 'h','x','l','l','o'> str_hxllo;
  
  typedef keyword<str_hello> keyword_hello;
}

BOOST_AUTO_TEST_CASE(test_keyword)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::get_remaining;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal;

  meta_require<has_type<keyword_hello> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<keyword<str_hello, char_l>, str_hello, start>
      >::type,
      char_l
    >
  >(MPLLIBS_HERE, "test_result_type");

  meta_require<
    equal_to<
      get_result<apply_wrap2<keyword<str_, char_l>, str_hello, start> >::type,
      char_l
    >
  >(MPLLIBS_HERE, "test_empty_keyword");

  meta_require<
    is_error<apply_wrap2<keyword_hello, str_, start> >
  >(MPLLIBS_HERE, "test_empty_input");

  meta_require<
    equal<
      get_remaining<apply_wrap2<keyword_hello, str_hello, start> >::type,
      str_
    >
  >(MPLLIBS_HERE, "test_itself");

  meta_require<
    equal<
      get_remaining<apply_wrap2<keyword_hello, str_hello_world, start> >::type,
      list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
  >(MPLLIBS_HERE, "test_more_than_itself");

  meta_require<
    is_error<apply_wrap2<keyword_hello, str_hellx, start> >
  >(MPLLIBS_HERE, "test_no_match_at_end");

  meta_require<
    is_error<apply_wrap2<keyword_hello, str_hxllo, start> >
  >(MPLLIBS_HERE, "test_no_match_in_the_middle");
}

