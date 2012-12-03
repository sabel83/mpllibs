#ifndef MPLLIBS_METAMONAD_TEST_COMMON_HPP
#define MPLLIBS_METAMONAD_TEST_COMMON_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>

#include "either_monad.hpp"

namespace
{
  struct x;
  struct y;
  
  typedef boost::mpl::int_<0> int0;
  typedef boost::mpl::int_<1> int1;
  typedef boost::mpl::int_<2> int2;
  typedef boost::mpl::int_<4> int4;
  typedef boost::mpl::int_<9> int9;
  typedef boost::mpl::int_<11> int11;
  typedef boost::mpl::int_<13> int13;
  typedef boost::mpl::int_<24> int24;
  typedef boost::mpl::int_<26> int26;
  typedef boost::mpl::int_<37> int37;

  template <class T>
  struct double_value : boost::mpl::times<T, int2> {};
  
  template <class T>
  struct lazy_double_value : boost::mpl::times<typename T::type, int2> {};
  
  template <class A, class B>
  struct lazy_plus : boost::mpl::plus<typename A::type, typename B::type> {};

  template <class A, class B>
  struct double_lazy_plus :
    boost::mpl::plus<typename A::type::type, typename B::type::type> {};

  template <class A, class B>
  struct lazy_times : boost::mpl::times<typename A::type, typename B::type> {};

  template <class C, class T, class F>
  struct lazy_eval_if : boost::mpl::eval_if<typename C::type, T, F> {};

  template <class A, class B>
  struct lazy_equal_to :
    boost::mpl::equal_to<typename A::type, typename B::type>
  {};

  template <class F, class A1>
  struct lazy_apply : boost::mpl::apply<typename F::type, A1> {};

  // Needed by laziness tests

  struct returns13
  {
    typedef int13 type;
  };

  template <class A, class B>
  struct non_lazy_plus : boost::mpl::int_<A::value + B::value> {};

  template <class C, class T, class F>
  struct custom_eval_if : boost::mpl::eval_if<C, T, F> {};

  typedef boost::mpl::divides<int1, int0> breaking_expr;
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, double_value, "double_value")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, lazy_double_value, "lazy_double_value")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_plus, "lazy_plus")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, double_lazy_plus, "double_lazy_plus")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_times, "lazy_times")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, lazy_eval_if, "lazy_eval_if")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_equal_to, "lazy_equal_to")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_apply, "lazy_apply")

#endif

