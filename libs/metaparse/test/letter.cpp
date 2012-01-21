// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/letter.hpp>
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

BOOST_AUTO_TEST_CASE(test_letter)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::letter;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  meta_require<has_type<letter> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<get_result<apply_wrap2<letter, str_hello, start> >::type, char_h>
  >(MPLLIBS_HERE, "test_with_text");
  
  meta_require<
    is_error<apply_wrap2<letter, str_1983, start> >
  >(MPLLIBS_HERE, "test_with_number");
  
  meta_require<
    is_error<apply_wrap2<letter, str_, start> >
  >(MPLLIBS_HERE, "test_with_empty_string");
}


