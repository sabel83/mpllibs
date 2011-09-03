// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_letter.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/not.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::util::is_letter;

using boost::mpl::apply_wrap1;
using boost::mpl::not_;

namespace
{
  const suite_path suite = suite_path("util")("is_letter");

  typedef has_type<is_letter> test_has_type;

  typedef apply_wrap1<is_letter, char_k> test_lcase_letter;
  
  typedef apply_wrap1<is_letter, char_K> test_ucase_letter;
    
  typedef not_<apply_wrap1<is_letter, char_7> > test_not_letter;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_lcase_letter)
MPLLIBS_ADD_TEST(suite, test_ucase_letter)
MPLLIBS_ADD_TEST(suite, test_not_letter)



