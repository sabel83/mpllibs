// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/make_syntax.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_make_syntax)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::make_syntax;
  using mpllibs::metamonad::returns;

  using boost::mpl::plus;

  using boost::is_same;

  meta_require<
    is_same<syntax<int13>, make_syntax<int13>::type>
  >(MPLLIBS_HERE, "test_making_a_syntax");

  meta_require<
    is_same<syntax<int13>, make_syntax<returns<int13> >::type>
  >(MPLLIBS_HERE, "test_laziness_of_make_syntax");
}


