// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any_one_of.h>
#include <mpllibs/metaparse/one_char.h>
#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/keyword.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include <mpllibs/metaparse/util/define_data.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::fail;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::any_one_of;
using mpllibs::metaparse::start;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::keyword;

using boost::mpl::equal;
using boost::mpl::apply;
using boost::mpl::list;
using boost::mpl::string;

namespace
{
  const test_suite suite("any_one_of");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);
  
  typedef fail<test_error> test_fail;

  typedef
    equal<get_result<apply<any_one_of< >, str_hello, start> >::type, list<> >
    test0;
  
  typedef
    equal<
      get_result<apply< any_one_of<one_char>, str_hello, start> >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test_good_sequence;

  typedef
    equal<
      get_result<apply<any_one_of<test_fail>, str_hello, start> >::type,
      list< >
    >
    test_1_with_bad;

  typedef
    equal<
      get_result<
        apply<any_one_of<one_char, test_fail>, str_hello, start>
      >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test_2_with_first_good;

  typedef
    equal<
      get_result<
        apply<any_one_of<test_fail, one_char>, str_hello, start>
      >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test_2_with_second_good;

  typedef keyword<str_h, char_h> keyword_h;
  typedef keyword<str_e, char_e> keyword_e;
  typedef keyword<str_l, char_l> keyword_l;

  typedef
    equal<
      get_result<
        apply<any_one_of<keyword_h, keyword_e, keyword_l>, str_hello, start>
      >::type,
      list<char_h, char_e, char_l, char_l>
    >
    test_accept_any_argument;
}

MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test_good_sequence)
MPLLIBS_ADD_TEST(suite, test_1_with_bad)
MPLLIBS_ADD_TEST(suite, test_2_with_first_good)
MPLLIBS_ADD_TEST(suite, test_2_with_second_good)
MPLLIBS_ADD_TEST(suite, test_accept_any_argument)

