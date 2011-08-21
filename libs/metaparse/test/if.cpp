// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/if.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::if_;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::start;

using boost::mpl::equal_to;
using boost::mpl::apply_wrap2;

namespace
{
  const suite_path suite("if");

  typedef has_type<if_<digit, int11, int13> > test_has_type;

  typedef
    equal_to<
      get_result<apply_wrap2<if_<digit, int11, int13>, str_1, start> >::type,
      int11
    >
    test_true;
    
  typedef
    equal_to<
      get_result<apply_wrap2<if_<digit, int11, int13>, str_a, start> >::type,
      int13
    >
    test_false;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_true)
MPLLIBS_ADD_TEST(suite, test_false)

