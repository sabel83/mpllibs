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

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_util_in_range)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::util::in_range;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::not_;

  meta_require<
    has_type<in_range<int10, int13> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    apply_wrap1<in_range<int10, int13>, int12>
  >(MPLLIBS_HERE, "test_int_in_range");

  meta_require<
    apply_wrap1<in_range<int10, int13>, int10>
  >(MPLLIBS_HERE, "test_lower_bound");

  meta_require<
    apply_wrap1<in_range<int10, int13>, int13>
  >(MPLLIBS_HERE, "test_upper_bound");

  meta_require<
    not_<apply_wrap1<in_range<int10, int13>, int14> >
  >(MPLLIBS_HERE, "test_int_not_in_range");
}

