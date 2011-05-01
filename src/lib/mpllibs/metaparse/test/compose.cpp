// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/compose.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/type_traits/is_same.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::util::compose;

using boost::mpl::identity;
using boost::mpl::plus;
using boost::mpl::times;
using boost::mpl::apply;
using boost::mpl::equal_to;

using boost::is_same;

namespace
{
  const test_suite suite("util::compose");

  struct make_pointer
  {
    template <class T>
    struct apply : identity<T*> {};
  };
  
  struct incr
  {
    template <class T>
    struct apply : plus<int13, T> {};
  };

  struct double_value
  {
    template <class T>
    struct apply : times<int2, T> {};
  };

  struct take_first
  {
    template <class A, class B>
    struct apply : identity<A> {};
  };

  typedef
    is_same<apply<compose<make_pointer, make_pointer>, int>::type, int**>
    test_same_function_twice;

  typedef
    is_same<
      apply<
        compose<
          make_pointer,
          make_pointer,
          make_pointer,
          make_pointer,
          make_pointer
        >,
        int
      >::type,
      int*****
    >
    test_same_function_five_times;

  typedef
    equal_to<apply<compose<double_value, incr>, int1>::type, int28>
    test_order;

  typedef
    equal_to<apply<compose<double_value, take_first>, int1, int3>::type, int2>
    test_two_arguments_for_the_first_function;
}

MPLLIBS_ADD_TEST(suite, test_same_function_twice)
MPLLIBS_ADD_TEST(suite, test_same_function_five_times)
MPLLIBS_ADD_TEST(suite, test_order)
MPLLIBS_ADD_TEST(suite, test_two_arguments_for_the_first_function)


