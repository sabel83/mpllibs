// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_nothing.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("lit");

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<lit_h, str_hello>::type::first,
      char_h
    >
    TestAccept;

  typedef
    mpllibs::metaparse::util::is_nothing<boost::mpl::apply<lit_h, str_bello> >
    TestReject;

  typedef
    mpllibs::metaparse::util::is_nothing<boost::mpl::apply<lit_h, str_> >
    TestWithEmptyString;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        lit_e,
        boost::mpl::apply<lit_h, str_hello>::type::second
      >::type::first,
      char_e
    >
    TestRemainingString;
}

MPLLIBS_ADD_TEST(suite, TestAccept)
MPLLIBS_ADD_TEST(suite, TestReject)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)
MPLLIBS_ADD_TEST(suite, TestRemainingString)


