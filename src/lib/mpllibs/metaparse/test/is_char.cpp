// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_char.h>

#include "common.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::is_char;

using boost::mpl::apply;

namespace
{
  const suite_path suite = suite_path("util")("is_char");

  typedef is_char<char_a> is_char_a;

  typedef apply<is_char_a, char_a> test_same;
  
  typedef apply<is_char_a, char_b> test_different;
}

MPLLIBS_ADD_TEST(suite, test_same)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_different)

