// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;

using boost::mpl::apply_wrap2;
using boost::mpl::equal_to;

namespace
{
  const suite_path suite("digit");

  typedef has_type<digit> test_has_type;

  typedef is_error<apply_wrap2<digit, str_hello, start> > test_with_text;
  
  typedef
    equal_to<get_result<apply_wrap2<digit, str_1983, start> >::type, char_1>
    test_with_number;
  
  typedef is_error<apply_wrap2<digit, str_, start> > test_with_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_with_text)
MPLLIBS_ADD_TEST(suite, test_with_number)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)


