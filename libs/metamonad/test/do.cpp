// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.hpp"

using boost::mpl::apply;
using boost::mpl::equal_to;
using boost::mpl::minus;

using mpllibs::metamonad::do_;
using mpllibs::metamonad::set;
using mpllibs::metamonad::do_return;
using mpllibs::metamonad::tmp_tag;
using mpllibs::metamonad::tmp_value;

/*
 * WrapperMonad
 */
namespace
{
  struct wrapper_tag : tmp_tag<wrapper_tag> {};

  typedef wrapper_tag wrapper_monad;

  template <class T>
  struct wrapped : tmp_value<wrapped<T>, wrapper_tag>
  {
    typedef T value;
  };
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, wrapped, "wrapped")

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monad<wrapper_tag>
    {
      struct return_ : tmp_value<return_>
      {
        template <class T>
        struct apply : wrapped<T> {};
      };
      
      struct bind : tmp_value<bind>
      {
        template <class A, class F>
        struct apply : apply<F, A> {};
      };
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
  template <class A>
  struct minus_2 : right<typename minus<typename A::value, int2>::type> {};
  
  template <class T>
  struct eval_to_right : right<typename T::type> {};
}

BOOST_AUTO_TEST_CASE(test_do)
{
  using mpllibs::metatest::meta_require;

  meta_require<
    equal_to<
      right<int11>,
      do_<either>::apply<
        set<x, do_return<int13> >,
        minus_2<x>
      >::type
    >
  >(MPLLIBS_HERE, "test_do");

  meta_require<
    equal_to<
      right<int9>,
      do_<either>::apply<
        set<x, do_return<int13> >,
        set<y, minus_2<x> >,
        minus_2<y>
      >::type
    >
  >(MPLLIBS_HERE, "test_do_three_steps");

  meta_require<
    equal_to<
      right<int9>,
      do_<either>::apply<
        set<x, do_return<int13> >,
        set<y, minus_2<x> >,
        minus_2<x>,
        minus_2<y>
      >::type
    >
  >(MPLLIBS_HERE, "test_do_two_calls");

  meta_require<
    equal_to<
      right<int13>,
      do_<either>::apply<
        do_return<int11>,
        do_return<int13>
      >::type
    >
  >(MPLLIBS_HERE, "test_do_two_returns");

  meta_require<
    equal_to<
      right<right<int13> >,
      do_<either>::apply<
        do_return<
          do_<either>::apply<
            do_return<int13>
          >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_do_with_return");

  meta_require<
    equal_to<
      right<right<int13> >,
      do_<either>::apply<
        do_return<do_return<int13> >
      >::type
    >
  >(MPLLIBS_HERE, "test_contents_of_return_is_substituted");

  meta_require<
    equal_to<
      right<wrapped<int13> >,
      do_<either>::apply<
        eval_to_right<
          do_<wrapper_monad>::apply<
            do_return<int13>
          >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_do_with_different_monads");
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, minus_2, "minus_2")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, eval_to_right, "eval_to_right")



