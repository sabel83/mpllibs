// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include "common.hpp"

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_fail)
{
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::fail;
  using mpllibs::metaparse::start;
  
  using boost::mpl::apply_wrap2;

  // test_fail_for_non_empty_string
  BOOST_MPL_ASSERT((
    is_error<apply_wrap2<fail<test_failure>, str_hello, start> >
  ));
}

