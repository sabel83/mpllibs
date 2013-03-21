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

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_iterate)
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::iterate;
  using mpllibs::metaparse::one_char;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal;
  using boost::mpl::list;
  using boost::mpl::vector_c;

  // test_empty_input
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<iterate<one_char, int13>, str_, start> >
  ));

  // test0
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int0>, str_hello, start> >::type,
      list<>
    >
  ));

  // test1
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int1>, str_hello, start> >::type,
      vector_c<char, 'h'>
    >
  ));

  // test2
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int2>, str_hello, start> >::type,
      vector_c<char, 'h', 'e'>
    >
  ));

  // test3
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<iterate<one_char, int3>, str_hello, start> >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
  ));
}


