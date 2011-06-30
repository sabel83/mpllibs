// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any_one_of1.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metamonad/meta_atom.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::fail;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::any_one_of1;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::keyword;
using mpllibs::metaparse::error_tag;

using boost::mpl::apply_wrap2;
using boost::mpl::equal;
using boost::mpl::list;
using boost::mpl::string;

namespace
{
  const suite_path suite("any_one_of1");
  
  MPLLIBS_DEFINE_META_ATOM(error_tag, test_error)
  
  typedef has_type<any_one_of1<one_char> > test_has_type;

  typedef fail<test_error> test_fail;

  typedef is_error<apply_wrap2<any_one_of1< >, str_hello, start> > test0;
  
  typedef
    equal<
      get_result<apply_wrap2<any_one_of1<one_char>, str_hello, start> >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test_good_sequence;

  typedef
    is_error<apply_wrap2<any_one_of1<test_fail>, str_hello, start> >
    test_1_with_bad;

  typedef
    equal<
      get_result<
        apply_wrap2<any_one_of1<one_char, test_fail>, str_hello, start>
      >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test_2_with_first_good;

  typedef
    equal<
      get_result<
        apply_wrap2<any_one_of1<test_fail, one_char>, str_hello, start>
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
        apply_wrap2<
          any_one_of1<keyword_h, keyword_e, keyword_l>,
          str_hello,
          start
        >
      >::type,
      list<char_h, char_e, char_l, char_l>
    >
    test_accept_any_argument;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test_good_sequence)
MPLLIBS_ADD_TEST(suite, test_1_with_bad)
MPLLIBS_ADD_TEST(suite, test_2_with_first_good)
MPLLIBS_ADD_TEST(suite, test_2_with_second_good)
MPLLIBS_ADD_TEST(suite, test_accept_any_argument)

