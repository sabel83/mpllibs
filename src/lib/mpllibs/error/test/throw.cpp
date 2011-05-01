// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/throw.h>
#include <mpllibs/error/exception.h>
#include <mpllibs/error/do_.h>

#include <mpllibs/error/get_data.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/type_traits/is_same.hpp>

#include "common.h"

using boost::mpl::equal_to;

using mpllibs::metatest::test_suite;

using mpllibs::error::get_data;
using mpllibs::error::exception_monad;

namespace
{
  const test_suite suite("THROW");
  
  typedef equal_to<int13, get_data<THROW<int13> >::type> test_get_data;

  
  typedef
    equal_to<
      int13,
      get_data<
        DO<exception_monad>::apply<
          THROW<int13>
        >::type
      >::type
    >
    test_monadic_exception;


  typedef
    equal_to<
      int11,
      get_data<
        DO<exception_monad>::apply<
          THROW<int11>,
          RETURN<int13>
        >::type
      >::type
    >
    test_exception_propagation;
}

MPLLIBS_ADD_TEST(suite, test_get_data)

MPLLIBS_ADD_TEST(suite, test_monadic_exception)
MPLLIBS_ADD_TEST(suite, test_exception_propagation)


