// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_lit_c)
{
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::get_remaining;
  using mpllibs::metaparse::get_position;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  // test_accept
  BOOST_MPL_ASSERT((
    equal_to<get_result<apply_wrap2<lit_c_h, str_hello, start> >::type, char_h>
  ));

  // test_reject
  BOOST_MPL_ASSERT((is_error<apply_wrap2<lit_c_h, str_bello, start> >));

  // test_with_empty_string
  BOOST_MPL_ASSERT((is_error< apply_wrap2<lit_c_h, str_, start> >));

  // test_remaining_string
  BOOST_MPL_ASSERT((
    equal_to<
      get_result<
        apply_wrap2<
          lit_c_e,
          get_remaining<apply_wrap2<lit_c_h, str_hello, start> >::type,
          get_position<apply_wrap2<lit_c_h, str_hello, start> >::type
        >
      >::type,
      char_e
    >
  ));
}


