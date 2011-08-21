// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_char.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::util::is_char;

using boost::mpl::apply_wrap1;

namespace
{
  const suite_path suite = suite_path("util")("is_char");

  typedef is_char<char_a> is_char_a;

  typedef has_type<is_char_a> test_has_type;

  typedef apply_wrap1<is_char_a, char_a> test_same;
  
  typedef apply_wrap1<is_char_a, char_b> test_different;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_same)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_different)

