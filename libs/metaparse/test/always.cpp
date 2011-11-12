// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_always)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::always;
  using mpllibs::metaparse::digit;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  typedef always<digit, int13> always_digit_13;

  typedef has_type<always_digit_13> test_has_type;

  meta_require<
    equal_to<
      get_result<apply_wrap2<always_digit_13, str_1, start> >::type,
      int13
    >
  >(MPLLIBS_HERE, "test_result");
  
  meta_require<
    is_error<apply_wrap2<always_digit_13, str_a, start> >
  >(MPLLIBS_HERE, "test_fail");
}

