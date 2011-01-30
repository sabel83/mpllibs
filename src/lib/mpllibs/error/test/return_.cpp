// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/return_.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>

#include "common.h"

namespace
{
  struct test_tag;
  
  struct Test
  {
    typedef test_tag tag;
  };
}

namespace mpllibs
{
  namespace error
  {
    template <>
    struct return__impl<test_tag>
    {
      template <class t>
      struct apply : boost::mpl::identity<int13> {};
    };
  }
}

namespace
{
  const mpllibs::metatest::TestSuite suite("return_");

  typedef
    boost::mpl::equal_to<
      int13,
      boost::mpl::apply<mpllibs::error::return_<Test>, int>::type
    >
    TestSpecialisationIsCalled;  

  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::error::return_<Test, int>::type
    >
    TestUsingTwoArguments;  
}

MPLLIBS_ADD_TEST(suite, TestSpecialisationIsCalled)
MPLLIBS_ADD_TEST(suite, TestUsingTwoArguments)


