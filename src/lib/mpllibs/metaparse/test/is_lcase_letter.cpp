// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_lcase_letter.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::is_lcase_letter");

  typedef
    boost::mpl::apply<mpllibs::metaparse::util::is_lcase_letter, char_k>
    TestLetter;
  
  typedef
    boost::mpl::apply<mpllibs::metaparse::util::is_lcase_letter, char_K>
    TestNonLetter;
}

MPLLIBS_ADD_TEST(suite, TestLetter)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonLetter)

