// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.hpp"

using boost::mpl::apply;
using boost::mpl::equal_to;
using boost::mpl::minus;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::do_;
using mpllibs::metamonad::set;
using mpllibs::metamonad::do_return;

/*
 * WrapperMonad
 */
namespace
{
  MPLLIBS_DEFINE_TAG(wrapper_tag)

  typedef wrapper_tag wrapper_monad;

  template <class T>
  struct wrapped
  {
    typedef wrapper_tag tag;
    typedef T value;
    typedef wrapped type;
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
      struct return_
      {
        typedef return_ type;

        template <class T>
        struct apply : wrapped<T> {};
      };
      
      struct bind
      {
        typedef bind type;

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
  const suite_path suite("do_");
  
  template <class A>
  struct minus_2 : right<typename minus<typename A::value, int2>::type> {};
  
  template <class T>
  struct eval_to_right : right<typename T::type> {};

  typedef
    equal_to<
      right<int11>,
      do_<either>::apply<
        set<x, do_return<int13> >,
        minus_2<x>
      >::type
    >
    test_do;

  typedef
    equal_to<
      right<int9>,
      do_<either>::apply<
        set<x, do_return<int13> >,
        set<y, minus_2<x> >,
        minus_2<y>
      >::type
    >
    test_do_three_steps;

  typedef
    equal_to<
      right<int9>,
      do_<either>::apply<
        set<x, do_return<int13> >,
        set<y, minus_2<x> >,
        minus_2<x>,
        minus_2<y>
      >::type
    >
    test_do_two_calls;

  typedef
    equal_to<
      right<int13>,
      do_<either>::apply<
        do_return<int11>,
        do_return<int13>
      >::type
    >
    test_do_two_returns;

  typedef
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
    test_nested_do_with_return;

  typedef
    equal_to<
      right<right<int13> >,
      do_<either>::apply<
        do_return<do_return<int13> >
      >::type
    >
    test_contents_of_return_is_substituted;

  typedef
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
    test_nested_do_with_different_monads;
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, minus_2, "minus_2")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, eval_to_right, "eval_to_right")

MPLLIBS_ADD_TEST(suite, test_do)
MPLLIBS_ADD_TEST(suite, test_do_three_steps)
MPLLIBS_ADD_TEST(suite, test_do_two_calls)
MPLLIBS_ADD_TEST(suite, test_do_two_returns)
MPLLIBS_ADD_TEST(suite, test_nested_do_with_return)
MPLLIBS_ADD_TEST(suite, test_contents_of_return_is_substituted)
MPLLIBS_ADD_TEST(suite, test_nested_do_with_different_monads)





