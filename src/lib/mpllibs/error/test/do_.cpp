// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/do_.h>

#include <mpllibs/metatest/test.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.h"

using boost::mpl::apply;
using boost::mpl::equal_to;
using boost::mpl::minus;

using mpllibs::metatest::suite_path;

/*
 * WrapperMonad
 */
namespace
{
  struct wrapper_tag
  {
    typedef wrapper_tag type;
  };

  typedef wrapper_tag wrapper_monad;

  template <class T>
  struct wrapped
  {
    typedef wrapper_tag tag;
    typedef T value;
    typedef wrapped type;
  };
}

namespace mpllibs
{
  namespace error
  {
    template <>
    struct return__impl<wrapper_tag>
    {
      template <class T>
      struct apply : wrapped<T> {};
    };

    template <>
    struct bind_impl<wrapper_tag>
    {
      template <class A, class F>
      struct apply : apply<F, A> {};
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<wrapper_tag, wrapper_tag>
    {
      template <class A, class B>
      struct apply : equal_to<typename A::value, typename B::value>
      {};
    };
  }
}

namespace
{
  const suite_path suite("do_");
  
  template <class A>
  struct minus_2 :
    right<typename minus<typename A::value, int2>::type>
  {};
  
  template <class T>
  struct eval_to_right : right<typename T::type> {};

  typedef
    equal_to<
      right<int11>,
      DO<either>::apply<
        SET<x, RETURN<int13> >,
        minus_2<x>
      >::type
    >
    test_do;

  typedef
    equal_to<
      right<int9>,
      DO<either>::apply<
        SET<x, RETURN<int13> >,
        SET<y, minus_2<x> >,
        minus_2<y>
      >::type
    >
    test_do_three_steps;

  typedef
    equal_to<
      right<int9>,
      DO<either>::apply<
        SET<x, RETURN<int13> >,
        SET<y, minus_2<x> >,
        minus_2<x>,
        minus_2<y>
      >::type
    >
    test_do_two_calls;

  typedef
    equal_to<
      right<int13>,
      DO<either>::apply<
        RETURN<int11>,
        RETURN<int13>
      >::type
    >
    test_do_two_returns;

  typedef
    equal_to<
      right<right<int13> >,
      DO<either>::apply<
        RETURN<
          DO<either>::apply<
            RETURN<int13>
          >
        >
      >::type
    >
    test_nested_do_with_return;

  typedef
    equal_to<
      right<right<int13> >,
      DO<either>::apply<
        RETURN<RETURN<int13> >
      >::type
    >
    test_contents_of_return_is_substituted;

  typedef
    equal_to<
      right<wrapped<int13> >,
      DO<either>::apply<
        eval_to_right<
          DO<wrapper_monad>::apply<
            RETURN<int13>
          >
        >
      >::type
    >
    test_nested_do_with_different_monads;
}

MPLLIBS_ADD_TEST(suite, test_do)
MPLLIBS_ADD_TEST(suite, test_do_three_steps)
MPLLIBS_ADD_TEST(suite, test_do_two_calls)
MPLLIBS_ADD_TEST(suite, test_do_two_returns)
MPLLIBS_ADD_TEST(suite, test_nested_do_with_return)
MPLLIBS_ADD_TEST(suite, test_contents_of_return_is_substituted)
MPLLIBS_ADD_TEST(suite, test_nested_do_with_different_monads)





