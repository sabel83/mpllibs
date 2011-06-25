// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_whitespace.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::util::is_whitespace;

using boost::mpl::apply_wrap1;

namespace
{
  const suite_path suite = suite_path("util")("is_whitespace");

  typedef has_type<is_whitespace> test_has_type;

  typedef apply_wrap1<is_whitespace, char_space> test_space;
  
  typedef apply_wrap1<is_whitespace, char_tab> test_tab;
  
  typedef apply_wrap1<is_whitespace, char_a> test_non_whitespace;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_space)
MPLLIBS_ADD_TEST(suite, test_tab)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_non_whitespace)


