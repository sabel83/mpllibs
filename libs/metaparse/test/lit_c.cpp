// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_lit_c)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::get_remaining;
  using mpllibs::metaparse::get_position;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  meta_require<has_type<lit_c_h> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<get_result<apply_wrap2<lit_c_h, str_hello, start> >::type, char_h>
  >(MPLLIBS_HERE, "test_accept");

  meta_require<
    is_error<apply_wrap2<lit_c_h, str_bello, start> >
  >(MPLLIBS_HERE, "test_reject");

  meta_require<
    is_error< apply_wrap2<lit_c_h, str_, start> >
  >(MPLLIBS_HERE, "test_with_empty_string");

  meta_require<
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
  >(MPLLIBS_HERE, "test_remaining_string");
}


