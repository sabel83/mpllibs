// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/curry.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/identity.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("util::curry");
  
  template <class a, class b>
  struct getFirst : boost::mpl::identity<a> {};
  
  template <class a, class b>
  struct getSecond : boost::mpl::identity<b> {};
  
  struct nullaryMetafunction : boost::mpl::identity<int13> {};
  
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        boost::mpl::apply<
          mpllibs::metaparse::util::curry2<getFirst>,
          int11
        >::type,
        int13
      >::type,
      int11
    >
    TestCurryingFirstArgument;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        boost::mpl::apply<
          mpllibs::metaparse::util::curry2<getSecond>,
          int11
        >::type,
        int13
      >::type,
      int13
    >
    TestCurryingSecondArgument;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::util::curry0<nullaryMetafunction>::type,
      int13
    >
    TestNullary;
}

MPLLIBS_ADD_TEST(suite, TestCurryingFirstArgument)
MPLLIBS_ADD_TEST(suite, TestCurryingSecondArgument)
MPLLIBS_ADD_TEST(suite, TestNullary)

