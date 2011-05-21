// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_ucase_letter.h>

#include "common.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::is_ucase_letter;

using boost::mpl::apply;

namespace
{
  const suite_path suite = suite_path("util")("is_ucase_letter");

  typedef apply<is_ucase_letter, char_K> test_letter;
  
  typedef apply<is_ucase_letter, char_k> test_non_letter;
}

MPLLIBS_ADD_TEST(suite, test_letter)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_non_letter)



