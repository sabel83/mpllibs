// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/do_c.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/eval_let.hpp>
#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/either.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include "common.hpp"

using boost::mpl::minus;

using mpllibs::metamonad::tmp_tag;
using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::returns;
using mpllibs::metamonad::lazy;
using mpllibs::metamonad::right;

/*
 * WrapperMonad
 */
namespace
{
  struct wrapper_tag : tmp_tag<wrapper_tag> {};

  typedef wrapper_tag wrapper_monad;

  MPLLIBS_METAFUNCTION(wrapped, (T)) ((tmp_value<wrapped<T>, wrapper_tag>));

  template <class T>
  struct unwrap;

  template <class T>
  struct unwrap<wrapped<T> > : returns<T> {};
}

namespace mpllibs
{
  namespace metamonad
  {
    template <>
    struct monad<wrapper_tag>
    {
      typedef lambda_c<t, wrapped<t> > return_;
      typedef lambda_c<a, f, apply<f, a> > bind;
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
      MPLLIBS_LAZY_METAFUNCTION(apply, (A)(B))
      ((lazy<equal_to<unwrap<A>, unwrap<B> > >));
    };
  }
}

namespace
{
  MPLLIBS_LAZY_METAFUNCTION(minus_2, (A)) ((right<minus<A, int2> >));
  
  MPLLIBS_LAZY_METAFUNCTION(eval_to_right, (T)) ((right<T>));
}

BOOST_AUTO_TEST_CASE(test_do_c)
{
  using mpllibs::metamonad::do_c;
  using mpllibs::metamonad::let;
  using mpllibs::metamonad::eval_let;
  using mpllibs::metamonad::either_tag;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::set;
  using mpllibs::metamonad::do_return;

  using boost::is_same;

  using boost::mpl::tag;
  using boost::mpl::equal_to;

  typedef tag<int13>::type int_tag;
  typedef either_tag<int_tag, int_tag> either;

  // test_do
  BOOST_MPL_ASSERT((
    equal_to<
      right<int11>,
      do_c<either,
        set<x, do_return<int13> >,
        minus_2<x>
      >::type
    >
  ));

  // test_do_three_steps
  BOOST_MPL_ASSERT((
    equal_to<
      right<int9>,
      do_c<either,
        set<x, do_return<int13> >,
        set<y, minus_2<x> >,
        minus_2<y>
      >::type
    >
  ));

  // test_do_two_calls
  BOOST_MPL_ASSERT((
    equal_to<
      right<int9>,
      do_c<either,
        set<x, do_return<int13> >,
        set<y, minus_2<x> >,
        minus_2<x>,
        minus_2<y>
      >::type
    >
  ));

  // test_do_two_returns
  BOOST_MPL_ASSERT((
    equal_to<
      right<int13>,
      do_c<either,
        do_return<int11>,
        do_return<int13>
      >::type
    >
  ));

  // test_nested_do_with_return
  BOOST_MPL_ASSERT((
    equal_to<
      right<right<int13> >,
      do_c<either,
        do_return<
          do_c<either,
            do_return<int13>
          >
        >
      >::type
    >
  ));

  // test_contents_of_return_is_substituted
  BOOST_MPL_ASSERT((
    equal_to<
      right<right<int13> >,
      do_c<either,
        do_return<do_return<int13> >
      >::type
    >
  ));

  // test_nested_do_with_different_monads
  BOOST_MPL_ASSERT((
    equal_to<
      right<wrapped<int13> >,
      do_c<either,
        eval_to_right<
          do_c<wrapper_monad,
            do_return<int13>
          >
        >
      >::type
    >
  ));

  // test_set_in_let
  BOOST_MPL_ASSERT((
    equal_to<
      right<int13>,
      eval_let<
        x, syntax<int11>,
        syntax<
          do_c<either,
            set<x, do_return<int13> >,
            do_return<x>
          >
        >
      >::type
    >
  ));

  // test_argument_of_set_and_do_in_let
  BOOST_MPL_ASSERT((
    equal_to<
      right<int11>,
      eval_let<
        x, syntax<int11>,
        syntax<
          do_c<either,
            set<x, do_return<int13> >,
            do_return<int11>
          >
        >
      >::type
    >
  ));

  // test_let_before_override
  BOOST_MPL_ASSERT((
    equal_to<
      right<int11>,
      eval_let<
        x, syntax<int11>,
        syntax<
          do_c<either,
            set<y, do_return<x> >,
            set<x, do_return<int13> >,
            do_return<y>
          >
        >
      >::type
    >
  ));

  // test_na_arguments_of_do
  BOOST_MPL_ASSERT((
    is_same<
      syntax<do_c<either, do_return<int11> > >,
      let<
        x, syntax<int11>,
        syntax<do_c<either, do_return<int11> > >
      >::type
    >
  ));
}



