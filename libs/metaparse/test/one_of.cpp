// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metamonad/meta_atom.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  using mpllibs::metaparse::error_tag;
  using mpllibs::metaparse::fail;

  MPLLIBS_DEFINE_META_ATOM(error_tag, test_error)

  typedef fail<test_error> test_fail;
}

BOOST_AUTO_TEST_CASE(test_one_of)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::one_of_0;
  using mpllibs::metaparse::one_of_1;
  using mpllibs::metaparse::one_of_2;
  using mpllibs::metaparse::one_of;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::one_char;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  
  meta_require<has_type<one_of<one_char> > >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<apply_wrap2<one_of_0< >, str_hello, start> >
  >(MPLLIBS_HERE, "test0");
  
  meta_require<
    equal_to<
      get_result<apply_wrap2<one_of_1<one_char>, str_hello, start> >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_1_with_good");

  meta_require<
    is_error<apply_wrap2<one_of_1<test_fail>, str_hello, start> >
  >(MPLLIBS_HERE, "test_1_with_bad");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<one_of_2<one_char, one_char>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_2_with_two_good");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<one_of_2<one_char, test_fail>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_2_with_first_good");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<one_of_2<test_fail, one_char>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_2_with_second_good");

  meta_require<
    is_error<apply_wrap2<one_of_2<test_fail, test_fail>, str_hello, start> >
  >(MPLLIBS_HERE, "test_2_with_two_bad");





  meta_require<
    is_error<apply_wrap2<one_of< >, str_hello, start> >
  >(MPLLIBS_HERE, "test");
  
  meta_require<
    equal_to<
      get_result<apply_wrap2<one_of<one_char>, str_hello, start> >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_with_good");
  
  meta_require<
    is_error<apply_wrap2<one_of<test_fail>, str_hello, start> >
  >(MPLLIBS_HERE, "test_with_bad");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<one_of<one_char, one_char>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_with_two_good");
    
  meta_require<
    equal_to<
      get_result<
        apply_wrap2<one_of<one_char, test_fail>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_with_first_good");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<one_of<test_fail, one_char>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_with_second_good");

  meta_require<
    is_error<apply_wrap2<one_of<test_fail, test_fail>, str_hello, start> >
  >(MPLLIBS_HERE, "test_with_two_bad");
}


