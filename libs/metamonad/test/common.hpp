#ifndef MPLLIBS_METAMONAD_TEST_COMMON_HPP
#define MPLLIBS_METAMONAD_TEST_COMMON_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  using namespace mpllibs::metamonad::name;
  
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

  MPLLIBS_METAFUNCTION(eval, (T)) ((T));

  MPLLIBS_METAFUNCTION(double_value, (T)) ((boost::mpl::times<T, int2>));
  
  MPLLIBS_LAZY_METAFUNCTION(lazy_double_value, (T))
  ((boost::mpl::times<T, int2>));
  
  MPLLIBS_LAZY_METAFUNCTION(lazy_plus, (A)(B)) ((boost::mpl::plus<A, B>));

  MPLLIBS_LAZY_METAFUNCTION(double_lazy_plus, (A)(B))
  ((boost::mpl::plus<typename A::type, typename B::type>));

  MPLLIBS_LAZY_METAFUNCTION(lazy_times, (A)(B)) ((boost::mpl::times<A, B>));

  MPLLIBS_LAZY_METAFUNCTION(lazy_equal_to, (A)(B))
  ((boost::mpl::equal_to<A, B>));

  MPLLIBS_LAZY_METAFUNCTION(lazy_apply, (F)(A1)) ((boost::mpl::apply<F, A1>));

  // Needed by laziness tests

  typedef mpllibs::metamonad::returns<int13> returns13;

  MPLLIBS_METAFUNCTION(non_lazy_plus, (A)(B))
  ((boost::mpl::int_<A::value + B::value>));

  MPLLIBS_METAFUNCTION(custom_eval_if, (C)(T)(F))
  ((boost::mpl::if_<C, T, F>));

  typedef boost::mpl::divides<int1, int0> breaking_expr;
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, double_value, "double_value")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, lazy_double_value, "lazy_double_value")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_plus, "lazy_plus")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, double_lazy_plus, "double_lazy_plus")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_times, "lazy_times")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_equal_to, "lazy_equal_to")
MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(2, lazy_apply, "lazy_apply")

#endif

