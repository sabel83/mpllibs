// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/Exception.h>
#include <mpllibs/error/throw.h>
#include <mpllibs/error/do_.h>

#include <mpllibs/error/get_data.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/type_traits/is_same.hpp>

#include "common.h"

namespace
{
  const mpllibs::metatest::TestSuite suite("THROW");
  
  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::error::get_data<THROW<int13> >::type
    >
    TestGetData;

  
  typedef
    boost::mpl::equal_to<
      int13,
      mpllibs::error::get_data<
        DO<THROW<int13> >::type
      >::type
    >
    TestMonadicException;


  typedef
    boost::mpl::equal_to<
      int11,
      mpllibs::error::get_data<
        DO<
          THROW<int11>,
          RETURN<mpllibs::error::ExceptionMonad, int13>
        >::type
      >::type
    >
    TestExceptionPropagation;
}

MPLLIBS_ADD_TEST(suite, TestGetData)

MPLLIBS_ADD_TEST(suite, TestMonadicException)
MPLLIBS_ADD_TEST(suite, TestExceptionPropagation)


