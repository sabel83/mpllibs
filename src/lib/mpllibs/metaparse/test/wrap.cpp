// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/wrap.h>
#include <mpllibs/metaparse/unwrap.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("wrap");

  struct tag1;
  struct tag2;
  
  typedef mpllibs::metaparse::wrap<tag1> wrap1;
  typedef mpllibs::metaparse::wrap<tag2> wrap2;

  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::metaparse::unwrap<boost::mpl::apply<wrap1, int13> >::type
    >
    TestUnwrap;
  
  typedef
    boost::is_same<
      tag1,
      boost::mpl::tag<boost::mpl::apply<wrap1, int13>::type>::type
    >
    TestTag1;

  typedef
    boost::is_same<
      tag2,
      boost::mpl::tag<boost::mpl::apply<wrap2, int13>::type>::type
    >
    TestTag2;
}

MPLLIBS_ADD_TEST(suite, TestUnwrap)
MPLLIBS_ADD_TEST(suite, TestTag1)
MPLLIBS_ADD_TEST(suite, TestTag2)


