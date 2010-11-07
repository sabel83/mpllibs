// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/empty.h>
#include <mpllibs/metaparse/util/is_nothing.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("empty");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::empty<int13>, str_>::type::first,
      int13
    >
    TestAcceptEmpty;

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<mpllibs::metaparse::empty<int13>, str_a>
    >
    TestRejectNonEmpty;
}

MPLLIBS_ADD_TEST(suite, TestAcceptEmpty)
MPLLIBS_ADD_TEST(suite, TestRejectNonEmpty)


