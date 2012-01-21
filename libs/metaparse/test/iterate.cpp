// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/iterate.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/vector_c.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_iterate)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::iterate;
  using mpllibs::metaparse::one_char;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal;
  using boost::mpl::list;
  using boost::mpl::vector_c;

  meta_require<
    has_type<iterate<one_char, int0> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<apply_wrap2<iterate<one_char, int13>, str_, start> >
  >(MPLLIBS_HERE, "test_empty_input");

  meta_require<
    equal<
      get_result<apply_wrap2<iterate<one_char, int0>, str_hello, start> >::type,
      list<>
    >
  >(MPLLIBS_HERE, "test0");

  meta_require<
    equal<
      get_result<apply_wrap2<iterate<one_char, int1>, str_hello, start> >::type,
      vector_c<char, 'h'>
    >
  >(MPLLIBS_HERE, "test1");

  meta_require<
    equal<
      get_result<apply_wrap2<iterate<one_char, int2>, str_hello, start> >::type,
      vector_c<char, 'h', 'e'>
    >
  >(MPLLIBS_HERE, "test2");

  meta_require<
    equal<
      get_result<apply_wrap2<iterate<one_char, int3>, str_hello, start> >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
  >(MPLLIBS_HERE, "test3");
}


