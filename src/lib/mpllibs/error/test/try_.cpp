// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/try_.h>
#include <mpllibs/error/throw.h>

#include <mpllibs/error/get_data.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/identity.hpp>

#include <boost/type_traits/is_same.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("try_");
  
  struct tag1
  {
    typedef tag1 type;
  };
  
  struct e1
  {
    typedef tag1 tag;
    typedef e1 type;
  };
  
  struct tag2
  {
    typedef tag1 type;
  };
  
  struct e2
  {
    typedef tag2 tag;
    typedef e2 type;
  };
  
  typedef
    boost::mpl::equal_to<
      int13,
      TRY<
        RETURN<int13>
      >
      ::catch_<tag1, x, int11>
      ::type
    >
    TestNoException;

  typedef
    boost::mpl::equal_to<
      int11,
      TRY<
        THROW<e1>
      >
      ::catch_<tag1, x, boost::mpl::identity<int11> >
      ::type
    >
    TestCatch;

  typedef
    boost::mpl::equal_to<
      int13,
      TRY<
        THROW<int13>
      >
      ::catch_<boost::mpl::tag<int13>::type, x, boost::mpl::identity<x> >
      ::type
    >
    TestExceptionValueInCatch;

  typedef
    boost::mpl::equal_to<
      mpllibs::error::Exception<int13>,
      TRY<
        THROW<int13>
      >
      ::catch_<tag2, x, boost::mpl::identity<int11> >
      ::type
    >
    TestNotCatching;

  typedef
    boost::mpl::equal_to<
      int13,
      TRY<
        THROW<e2>
      >
      ::catch_<tag1, x, boost::mpl::identity<int11> >
      ::catch_<tag2, x, boost::mpl::identity<int13> >
      ::type
    >
    TestSecondCatch;

  typedef
    boost::mpl::equal_to<
      int11,
      TRY<
        THROW<e1>,
        RETURN<int1>
      >
      ::catch_<tag1, x, boost::mpl::identity<int11> >
      ::type
    >
    TestExceptionPropagation;


  typedef
    boost::mpl::equal_to<
      int11,
      TRY<
        RETURN<int13>,
        RETURN<int11>
      >
      ::catch_<tag1, x, boost::mpl::identity<int11> >
      ::type
    >
    TestExecutionSequence;
  
  typedef
    boost::mpl::equal_to<
      int11,
      TRY<
        SET<x, THROW<e1> >,
        RETURN<int1>
      >
      ::catch_<tag1, x, boost::mpl::identity<int11> >
      ::type
    >
    TestExceptionInSet;
}

MPLLIBS_ADD_TEST(suite, TestNoException)
MPLLIBS_ADD_TEST(suite, TestCatch)
MPLLIBS_ADD_TEST(suite, TestExceptionValueInCatch)
MPLLIBS_ADD_TEST(suite, TestNotCatching)
MPLLIBS_ADD_TEST(suite, TestSecondCatch)
MPLLIBS_ADD_TEST(suite, TestExceptionPropagation)
MPLLIBS_ADD_TEST(suite, TestExecutionSequence)
MPLLIBS_ADD_TEST(suite, TestExceptionInSet)


