// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/one_char.h>
#include <mpllibs/metaparse/fail.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include <mpllibs/metaparse/util/define_data.h>

#include "common.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::fail;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::one_of_0;
using mpllibs::metaparse::one_of_1;
using mpllibs::metaparse::one_of_2;
using mpllibs::metaparse::one_of;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::one_char;

using boost::mpl::apply;
using boost::mpl::equal_to;

namespace
{
  const suite_path suite("one_of");
  
  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);
  
  typedef fail<test_error> test_fail;

  typedef is_error<apply<one_of_0< >, str_hello, start> > test0;
  
  typedef
    equal_to<
      get_result<apply<one_of_1<one_char>, str_hello, start> >::type,
      char_h
    >
    test_1_with_good;

  typedef
    is_error<apply<one_of_1<test_fail>, str_hello, start> >
    test_1_with_bad;

  typedef
    equal_to<
      get_result<apply<one_of_2<one_char, one_char>, str_hello, start> >::type,
      char_h
    >
    test_2_with_two_good;

  typedef
    equal_to<
      get_result<apply<one_of_2<one_char, test_fail>, str_hello, start> >::type,
      char_h
    >
    test_2_with_first_good;

  typedef
    equal_to<
      get_result<apply<one_of_2<test_fail, one_char>, str_hello, start> >::type,
      char_h
    >
    test_2_with_second_good;

  typedef
    is_error<apply<one_of_2<test_fail, test_fail>, str_hello, start> >
    test_2_with_two_bad;





  typedef is_error<apply<one_of< >, str_hello, start> > test;
  
  typedef
    equal_to<
      get_result<apply<one_of<one_char>, str_hello, start> >::type,
      char_h
    >
    test_with_good;
  
  typedef
    is_error<apply<one_of<test_fail>, str_hello, start> >
    test_with_bad;

  typedef
    equal_to<
      get_result<apply<one_of<one_char, one_char>, str_hello, start> >::type,
      char_h
    >
    test_with_two_good;
    
  typedef
    equal_to<
      get_result<apply<one_of<one_char, test_fail>, str_hello, start> >::type,
      char_h
    >
    test_with_first_good;

  typedef
    equal_to<
      get_result<apply<one_of<test_fail, one_char>, str_hello, start> >::type,
      char_h
    >
    test_with_second_good;

  typedef
    is_error<apply<one_of<test_fail, test_fail>, str_hello, start> >
    test_with_two_bad;
}

MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test_1_with_good)
MPLLIBS_ADD_TEST(suite, test_1_with_bad)
MPLLIBS_ADD_TEST(suite, test_2_with_two_good)
MPLLIBS_ADD_TEST(suite, test_2_with_first_good)
MPLLIBS_ADD_TEST(suite, test_2_with_second_good)
MPLLIBS_ADD_TEST(suite, test_2_with_two_bad)

MPLLIBS_ADD_TEST(suite, test)
MPLLIBS_ADD_TEST(suite, test_with_good)
MPLLIBS_ADD_TEST(suite, test_with_bad)
MPLLIBS_ADD_TEST(suite, test_with_two_good)
MPLLIBS_ADD_TEST(suite, test_with_first_good)
MPLLIBS_ADD_TEST(suite, test_with_second_good)
MPLLIBS_ADD_TEST(suite, test_with_two_bad)


