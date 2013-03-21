// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/compose.hpp>

#include "common.hpp"

#include <boost/mpl/identity.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  using std::ostream;

  using boost::mpl::identity;
  using boost::mpl::plus;
  using boost::mpl::times;

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
}

BOOST_AUTO_TEST_CASE(test_compose)
{
  using mpllibs::metaparse::util::compose;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  
  using boost::is_same;

  // test_same_function_twice
  BOOST_MPL_ASSERT((
    is_same<apply_wrap1<compose<make_pointer, make_pointer>, int>::type, int**>
  ));

  // test_same_function_five_times
  BOOST_MPL_ASSERT((
    is_same<
      apply_wrap1<
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
  ));

  // test_order
  BOOST_MPL_ASSERT((
    equal_to<apply_wrap1<compose<double_value, incr>, int1>::type, int28>
  ));

  // test_two_arguments_for_the_first_function
  BOOST_MPL_ASSERT((
    equal_to<
      apply_wrap2<compose<double_value, take_first>, int1, int3>::type,
      int2
    >
  ));
}


