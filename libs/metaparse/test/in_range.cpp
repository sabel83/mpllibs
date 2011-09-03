// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/in_range.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/not.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::util::in_range;

using boost::mpl::apply_wrap1;
using boost::mpl::not_;

namespace
{
  const suite_path suite = suite_path("util")("in_range");

  typedef has_type<in_range<int10, int13> > test_has_type;

  typedef apply_wrap1<in_range<int10, int13>, int12> test_int_in_range;

  typedef apply_wrap1<in_range<int10, int13>, int10> test_lower_bound;

  typedef apply_wrap1<in_range<int10, int13>, int13> test_upper_bound;

  typedef
    not_<apply_wrap1<in_range<int10, int13>, int14> >
    test_int_not_in_range;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_int_in_range)
MPLLIBS_ADD_TEST(suite, test_lower_bound)
MPLLIBS_ADD_TEST(suite, test_upper_bound)
MPLLIBS_ADD_TEST(suite, test_int_not_in_range)

