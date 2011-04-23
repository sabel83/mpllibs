// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/keyword.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::keyword;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::get_remaining;

using boost::mpl::list_c;
using boost::mpl::equal_to;
using boost::mpl::apply;
using boost::mpl::equal;

namespace
{
  const TestSuite suite("keyword");

  typedef
    list_c<char, 'h','e','l','l','o',' ','w','o','r','l','d'>
    str_hello_world;
    
  typedef list_c<char, 'h','e','l','l','x'> str_hellx;
  typedef list_c<char, 'h','x','l','l','o'> str_hxllo;
  
  typedef keyword<str_hello> keyword_hello;

  typedef
    equal_to<
      get_result<apply<keyword<str_hello, char_l>, str_hello, start> >::type,
      char_l
    >
    test_result_type;

  typedef
    equal_to<
      get_result<apply<keyword<str_, char_l>, str_hello, start> >::type,
      char_l
    >
    test_empty_keyword;

  typedef is_error<apply<keyword_hello, str_, start> > test_empty_input;

  typedef
    equal<get_remaining<apply<keyword_hello, str_hello, start> >::type, str_>
    test_itself;

  typedef
    equal<
      get_remaining<apply<keyword_hello, str_hello_world, start> >::type,
      list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
    test_more_than_itself;

  typedef
    is_error<apply<keyword_hello, str_hellx, start> >
    test_no_match_at_end;

  typedef
    is_error<apply<keyword_hello, str_hxllo, start> >
    test_no_match_in_the_middle;
}

MPLLIBS_ADD_TEST(suite, test_result_type)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test_empty_keyword)
MPLLIBS_ADD_TEST(suite, test_itself)
MPLLIBS_ADD_TEST(suite, test_more_than_itself)
MPLLIBS_ADD_TEST(suite, test_no_match_at_end)
MPLLIBS_ADD_TEST(suite, test_no_match_in_the_middle)


