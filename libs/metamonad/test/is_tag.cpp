// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/is_tag.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/not.hpp>

#include "common.hpp"


BOOST_AUTO_TEST_CASE(test_is_tag)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::is_tag;
  using mpllibs::metamonad::returns;

  using boost::mpl::not_;

  meta_require<is_tag<int13::tag, int13> >(MPLLIBS_HERE, "test_with_two_args");

  meta_require<not_<is_tag<double, int13>::type> >(MPLLIBS_HERE, "test_false");

  meta_require<
    is_tag<int13::tag>::apply<int13>
  >(MPLLIBS_HERE, "test_currying");

  meta_require<
    is_tag<int13::tag, returns<int13> >
  >(MPLLIBS_HERE, "test_laziness_of_value");

  meta_require<
    is_tag<returns<int13::tag>, int13>
  >(MPLLIBS_HERE, "test_laziness_of_tag");
}



