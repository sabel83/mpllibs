// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/exception.h>
#include <mpllibs/error/do_.h>

#include <mpllibs/error/get_data.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/type_traits/is_same.hpp>

#include "common.h"

using boost::is_same;

using boost::mpl::equal_to;
using boost::mpl::always;
using boost::mpl::apply;
using boost::mpl::tag;

using mpllibs::metatest::TestSuite;

using mpllibs::error::exception;
using mpllibs::error::get_data;
using mpllibs::error::exception_monad;
using mpllibs::error::no_exception_tag;
using mpllibs::error::return_;

namespace
{
  const TestSuite suite("Exception");
  
  typedef exception<int13> e;

  typedef equal_to<int13, get_data<e>::type> test_get_data;

  typedef
    equal_to<
      int13,
      DO<exception_monad>::apply<
        RETURN<int13>
      >::type::type
    >
    test_monadic_no_exception;

  typedef
    equal_to<
      int13,
      get_data<
        DO<exception_monad>::apply<
          apply<always<e>, int>
        >::type
      >::type
    >
    test_monadic_exception;


  typedef
    equal_to<
      int13,
      get_data<
        DO<exception_monad>::apply<
          apply<always<e>, int>,
          RETURN<int13>
        >::type
      >::type
    >
    test_exception_propagation;


  typedef
    is_same<no_exception_tag, tag<return_<exception_monad, int13>::type>::type>
    test_return_tag;

  typedef
    is_same<
      no_exception_tag,
      tag<
        DO<exception_monad>::apply<
          RETURN<int11>
        >::type
      >::type
    >
    test_tag_with_1_element_do;

  typedef
    equal_to<
      int11,
      DO<exception_monad>::apply<
        RETURN<int13>,
        RETURN<int11>
      >::type::type // the last ::type unwraps the value
    >
    test_execution_sequence;
  
  struct x;
  
  typedef
    equal_to<
      int13,
      get_data<
        DO<exception_monad>::apply<
          SET<x, apply<always<e>, int> >,
          RETURN<int13>
        >::type
      >::type
    >
    test_exception_in_set;
}

MPLLIBS_ADD_TEST(suite, test_get_data)

MPLLIBS_ADD_TEST(suite, test_monadic_no_exception)
MPLLIBS_ADD_TEST(suite, test_monadic_exception)
MPLLIBS_ADD_TEST(suite, test_exception_propagation)
MPLLIBS_ADD_TEST(suite, test_tag_with_1_element_do)
MPLLIBS_ADD_TEST(suite, test_return_tag)
MPLLIBS_ADD_TEST(suite, test_execution_sequence)
MPLLIBS_ADD_TEST(suite, test_exception_in_set)


