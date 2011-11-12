// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/look_ahead.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/digit_val.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_look_ahead)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::look_ahead;
  using mpllibs::metaparse::digit_val;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::fail;
  using mpllibs::metaparse::get_remaining;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal;
 
  meta_require<
    has_type<look_ahead<digit_val> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<
      int1,
      get_result<apply_wrap2<look_ahead<digit_val>, str_1983, start> >::type
    >
  >(MPLLIBS_HERE, "test_returns_result");

  meta_require<
    is_error<apply_wrap2<look_ahead<fail<int13> >, str_1983, start> >
  >(MPLLIBS_HERE, "test_returns_error");

  meta_require<
    equal<
      str_1983,
      get_remaining<apply_wrap2<look_ahead<digit_val>, str_1983, start> >::type
    >
  >(MPLLIBS_HERE, "test_doesnt_process_input");
}


