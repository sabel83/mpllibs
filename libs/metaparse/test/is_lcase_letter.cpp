// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_lcase_letter.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/not.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_util_is_lcase_letter)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::util::is_lcase_letter;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::not_;

  meta_require<has_type<is_lcase_letter> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    apply_wrap1<is_lcase_letter, char_k>
  >(MPLLIBS_HERE, "test_letter");
  
  meta_require<
    not_<apply_wrap1<is_lcase_letter, char_K> >
  >(MPLLIBS_HERE, "test_non_letter");
}

