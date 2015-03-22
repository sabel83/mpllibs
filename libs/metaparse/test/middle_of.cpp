// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/error/unpaired.hpp>
#include <mpllibs/metaparse/error/literal_expected.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_middle_of)
{
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::middle_of;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::get_message;

  using mpllibs::metaparse::error::unpaired;
  using mpllibs::metaparse::error::literal_expected;
  
  using boost::is_same;

  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  // test_three_chars
  BOOST_MPL_ASSERT((
    equal_to<
      get_result<
        apply_wrap2<middle_of<lit_h, lit_e, lit_l>, str_hello, start>
      >::type,
      char_e
    >
  ));

  // test_first_fails
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<middle_of<lit_x, lit_e, lit_l>, str_hello, start> >
  ));

  // test_second_fails
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<middle_of<lit_h, lit_x, lit_l>, str_hello, start> >
  ));

  // test_third_fails
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<middle_of<lit_h, lit_e, lit_x>, str_hello, start> >
  ));

  // test_error_message_when_third_fails
  BOOST_MPL_ASSERT((
    is_same<
      unpaired<1, 1, literal_expected<'x'> >,
      get_message<
        apply_wrap2<middle_of<lit_h, lit_e, lit_x>, str_hello, start>
      >::type
    >
  ));

  // test_empty_input
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<middle_of<lit_h, lit_e, lit_l>, str_, start> >
  ));
}


