// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/if.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/apply_wrap.hpp>

using boost::mpl::int_;
using boost::mpl::minus;
using boost::mpl::times;
using boost::mpl::equal_to;
using boost::mpl::less;

using mpllibs::metamonad::lazy;
using mpllibs::metamonad::returns;
using mpllibs::metamonad::if_;

namespace
{
  MPLLIBS_LAZY_METAFUNCTION(not_using_arg, (T)) ((int_<13>));

  MPLLIBS_LAZY_METAFUNCTION(double_value, (N)) ((times<N, int_<2> >));

  MPLLIBS_LAZY_METAFUNCTION(fact, (N))
  ((
    if_<
      less<N, int_<1> >,
      int_<1>,
      lazy<times<fact<minus<N, int_<1> > >, N> >
    >
  ));

  MPLLIBS_LAZY_METAFUNCTION(mult, (A)(B)) ((times<A, B>));
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
    equal_to<int_<6>, apply_wrap1<mult<int_<2> >::type, int_<3> >::type>
  >(MPLLIBS_HERE, "test_currying");

  meta_require<
    equal_to<int_<6>, apply_wrap2<mult<>, int_<2>, int_<3> >::type>
  >(MPLLIBS_HERE, "test_using_metafunction_as_metafunction_class");

  meta_require<
    equal_to<int_<24>, mult<mult<int_<2>, int_<3> >, int_<4> >::type>
  >(MPLLIBS_HERE, "test_nested_lazy_metafunction_call");

  meta_require<
    equal_to<int_<6>, fact<int_<3> >::type>
  >(MPLLIBS_HERE, "test_lazy_rec_metafunction");

  meta_require<
    equal_to<int_<13>, not_using_arg<int_<8> >::type>
  >(MPLLIBS_HERE, "test_lazy_mf_not_using_arg");
}


