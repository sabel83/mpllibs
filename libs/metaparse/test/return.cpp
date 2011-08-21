// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/return.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::return_;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::get_remaining;
using mpllibs::metaparse::get_position;
using mpllibs::metaparse::start;

using boost::mpl::apply_wrap2;
using boost::mpl::equal_to;

namespace
{
  const suite_path suite("return");

  typedef apply_wrap2<return_<int1>, int2, int3> acc;
  
  typedef return_<char_x> return_x;

  typedef has_type<return_x> test_has_type;

  typedef
    equal_to<get_result<apply_wrap2<return_x, str_hello, start> >::type, char_x>
    test_for_non_empty_string;

  typedef
    equal_to<get_result<apply_wrap2<return_x, str_, start> >::type, char_x>
    test_for_empty_string;

 
  typedef equal_to<int1, get_result<acc>::type> test_get_result;

  typedef equal_to<int2, get_remaining<acc>::type> test_get_remaining;

  typedef equal_to<int3, get_position<acc>::type> test_get_position;
}

MPLLIBS_ADD_TEST(suite, test_has_type)

MPLLIBS_ADD_TEST(suite, test_for_empty_string)
MPLLIBS_ADD_TEST(suite, test_for_non_empty_string)

MPLLIBS_ADD_TEST(suite, test_get_result)
MPLLIBS_ADD_TEST(suite, test_get_remaining)
MPLLIBS_ADD_TEST(suite, test_get_position)

