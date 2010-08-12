// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/curry.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/plus.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("curry");
  
  template <class a, class b>
  struct getFirst
  {
    typedef a type;
  };
  
  template <class a, class b>
  struct getSecond
  {
    typedef b type;
  };

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        boost::mpl::apply<
          mpllibs::util::curry<boost::mpl::quote2<getFirst>, int2>::type,
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
          mpllibs::util::curry<boost::mpl::quote2<getSecond>, int2>::type,
          int11
        >::type,
        int13
      >::type,
      int13
    >
    TestCurryingSecondArgument;
}

MPLLIBS_ADD_TEST(suite, TestCurryingFirstArgument)
MPLLIBS_ADD_TEST(suite, TestCurryingSecondArgument)

