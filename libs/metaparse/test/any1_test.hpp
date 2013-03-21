// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This header file contains code that is reused by other cpp files

#include <mpllibs/metaparse/letter.hpp>
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

DEFINE_TEST_CASE
{ 
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::letter;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal;
  using boost::mpl::apply_wrap2;
  using boost::mpl::list;
  using boost::mpl::vector_c;

  typedef any1<letter> any1_letter;

  // test_empty_input
  BOOST_MPL_ASSERT((is_error<apply_wrap2<any1_letter, str_, start> >));
  
  // test0
  BOOST_MPL_ASSERT((is_error<apply_wrap2<any1_letter, chars0, start> >));
  
  // test1
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<any1_letter, chars1, start> >::type,
      vector_c<char, 'h'>
    >
  ));
  
  // test2
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<any1_letter, chars2, start> >::type,
      vector_c<char, 'h', 'e'>
    >
  ));
  
  // test3
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<any1_letter, chars3, start> >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
  ));

  // test4
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<any1_letter, chars4, start> >::type,
      vector_c<char, 'h', 'e', 'l', 'l'>
    >
  ));
  
  // test5
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<any1_letter, chars5, start> >::type,
      vector_c<char, 'h', 'e', 'l', 'l', 'o'>
    >
  ));
}


