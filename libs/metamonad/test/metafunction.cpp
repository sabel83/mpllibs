// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/apply_wrap.hpp>

using boost::mpl::int_;
using boost::mpl::minus;
using boost::mpl::times;
using boost::mpl::equal_to;
using boost::mpl::less;
using boost::mpl::eval_if;

using mpllibs::metamonad::lazy;

namespace
{
  MPLLIBS_METAFUNCTION(double_value, (class N)) ((times<N, int_<2> >));

  MPLLIBS_METAFUNCTION_CLASS(triple_value, (class N)) ((times<N, int_<3> >));

  MPLLIBS_REC_METAFUNCTION(fact, (class N))
  ((
    lazy<
      eval_if<
        less<N, int_<1> >,
        int_<1>,
        times<fact<minus<N, int_<1> > >, N>
      >
    >
  ));

  MPLLIBS_METAFUNCTION(mult, (class A)(class B)) ((times<A, B>));

  MPLLIBS_METAFUNCTION_CLASS(sub, (class A)(class B)) ((minus<A, B>));
}

BOOST_AUTO_TEST_CASE(test_metafunction)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;

  meta_require<
    equal_to<int_<6>, double_value<int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction");

  meta_require<
    equal_to<int_<6>, mult<int_<2>, int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction_with_two_arguments");

  meta_require<
    equal_to<int_<9>, apply_wrap1<triple_value, int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction_class");

  meta_require<
    equal_to<int_<11>, apply_wrap2<sub, int_<13>, int_<2> >::type>
  >(MPLLIBS_HERE, "test_metafunction_class_with_two_arguments");

  meta_require<
    equal_to<int_<9>, apply_wrap1<triple_value::type, int_<3> >::type>
  >(MPLLIBS_HERE, "test_metafunction_class_as_metaprogramming_value");

  meta_require<
    equal_to<int_<6>, fact<int_<3> >::type>
  >(MPLLIBS_HERE, "test_rec_metafunction");
}


