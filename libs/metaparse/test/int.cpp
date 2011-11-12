// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/int.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_int)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::int_;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;

  meta_require<has_type<int_> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<apply_wrap2<int_, str_hello, start> >
  >(MPLLIBS_HERE, "test_with_text");
  
  meta_require<
    equal_to<get_result<apply_wrap2<int_, str_0, start> >::type, int0>
  >(MPLLIBS_HERE, "test_with_zero");

  meta_require<
    equal_to<get_result<apply_wrap2<int_, str_1, start> >::type, int1>
  >(MPLLIBS_HERE, "test_with_one_digit");

  meta_require<
    equal_to<
      get_result<apply_wrap2<int_, str_1983, start> >::type,
      boost::mpl::int_<1983>
    >
  >(MPLLIBS_HERE, "test_with_big_number");
  
  meta_require<
    is_error<apply_wrap2<int_, str_, start> >
  >(MPLLIBS_HERE, "test_with_empty_string");
}

