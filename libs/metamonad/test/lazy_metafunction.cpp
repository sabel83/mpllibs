// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/config.hpp>

using boost::mpl::int_;
using boost::mpl::minus;
using boost::mpl::times;
using boost::mpl::equal_to;
using boost::mpl::less;
using boost::mpl::eval_if;

using mpllibs::metamonad::lazy;
using mpllibs::metamonad::returns;

#if defined(BOOST_NO_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)
  #define BOOST_NO_CXX11_VARIADIC_TEMPLATES
#endif

namespace
{
  MPLLIBS_LAZY_METAFUNCTION(not_using_arg, (T)) ((int_<13>));

  MPLLIBS_LAZY_METAFUNCTION(double_value, (N)) ((times<N, int_<2> >));

  MPLLIBS_LAZY_METAFUNCTION_CLASS(triple_value, (N)) ((times<N, int_<3> >));

  MPLLIBS_LAZY_METAFUNCTION(fact, (N))
  ((
    eval_if<
      less<N, int_<1> >,
      int_<1>,
      lazy<times<fact<minus<N, int_<1> > >, N> >
    >
  ));

  MPLLIBS_LAZY_METAFUNCTION(mult, (A)(B)) ((times<A, B>));

  MPLLIBS_LAZY_METAFUNCTION_CLASS(sub, (A)(B)) ((minus<A, B>));

  template <class A>
  MPLLIBS_LAZY_METAFUNCTION_CLASS(mult_c, (B)) ((times<A, B>));

#ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
  template <class... Ts>
  struct var_first;

  template <class T, class... Ts>
  struct var_first<T, Ts...> : returns<T> {};

  MPLLIBS_LAZY_VARIADIC_METAFUNCTION(variadic_mf, (A), B)
  ((times<A, typename var_first<B...>::type>));

  MPLLIBS_LAZY_VARIADIC_METAFUNCTION_CLASS(variadic_mfc, (A), B)
  ((times<A, typename var_first<B...>::type>));

  template <class A>
  MPLLIBS_LAZY_VARIADIC_METAFUNCTION_CLASS(variadic_tmfc, (X), B)
  ((times<A, typename var_first<B...>::type>));
#endif
}

BOOST_AUTO_TEST_CASE(test_lazy_metafunction)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;

  meta_require<
    equal_to<int_<6>, double_value<int_<3> >::type>
  >(MPLLIBS_HERE, "test_lazy_metafunction");

  meta_require<
    equal_to<int_<6>, mult<int_<2>, int_<3> >::type>
  >(MPLLIBS_HERE, "test_lazy_metafunction_with_two_arguments");

  meta_require<
    equal_to<int_<24>, mult<mult<int_<2>, int_<3> >, int_<4> >::type>
  >(MPLLIBS_HERE, "test_nested_lazy_metafunction_call");

  meta_require<
    equal_to<int_<9>, apply_wrap1<triple_value, int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction_class");

  meta_require<
    equal_to<int_<11>, apply_wrap2<sub, int_<13>, int_<2> >::type>
  >(MPLLIBS_HERE, "test_lazy_metafunction_class_with_two_arguments");

  meta_require<
    equal_to<int_<9>, apply_wrap1<triple_value::type, int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction_class_as_metaprogramming_value");

  meta_require<
    equal_to<int_<6>, fact<int_<3> >::type>
  >(MPLLIBS_HERE, "test_lazy_rec_metafunction");

  meta_require<
    equal_to<int_<13>, not_using_arg<int_<8> >::type>
  >(MPLLIBS_HERE, "test_lazy_mf_not_using_arg");

  meta_require<
    equal_to<int_<6>, apply_wrap1<mult_c<int_<2> >, int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction_class_with_template_argument");

#ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
  meta_require<
    equal_to<int_<6>, variadic_mf<int_<2>, int_<3>, int_<4>, int_<5> >::type>
  >(MPLLIBS_HERE, "test_variadic_metafunction");

  meta_require<
    equal_to<
      int_<6>,
      variadic_mfc::apply<int_<2>, int_<3>, int_<4>, int_<5> >::type
    >
  >(MPLLIBS_HERE, "test_variadic_metafunction_class");

  meta_require<
    equal_to<
      int_<6>,
      variadic_tmfc<int_<2> >::apply<int_<7>, int_<3>, int_<4>, int_<5> >::type
    >
  >(MPLLIBS_HERE, "test_variadic_template_metafunction_class");
#endif
}


