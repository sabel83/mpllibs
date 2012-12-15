// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/less.hpp>

using boost::mpl::int_;
using boost::mpl::minus;
using boost::mpl::times;
using boost::mpl::equal_to;
using boost::mpl::less;
using boost::mpl::eval_if;

namespace
{
  template <class N>
  MPLLIBS_LAZY_METAFUNCTION(double_value, (times<N, int_<2> >));

  template <class N>
  MPLLIBS_LAZY_REC_METAFUNCTION(
    fact,
    (
      eval_if<
        less<N, int_<1> >,
        int_<1>,
        times<fact<minus<N, int_<1> > >, N>
      >
    )
  );

  MPLLIBS_LAZY_METAFUNCTION(nullary_metafunction, (int_<13>));

  MPLLIBS_LAZY_REC_METAFUNCTION(nullary_rec_metafunction, (int_<13>));
}

BOOST_AUTO_TEST_CASE(test_lazy_metafunction)
{
  using mpllibs::metatest::meta_require;

  meta_require<
    equal_to<int_<6>, double_value<int_<3> >::type>
  >(MPLLIBS_HERE, "test_lazy_metafunction");

  meta_require<
    equal_to<int_<6>, fact<int_<3> >::type>
  >(MPLLIBS_HERE, "test_lazy_rec_metafunction");

  meta_require<
    equal_to<int_<13>, nullary_metafunction::type>
  >(MPLLIBS_HERE, "test_lazy_nullary_metafunction");

  meta_require<
    equal_to<int_<13>, nullary_rec_metafunction::type>
  >(MPLLIBS_HERE, "test_lazy_nullary_metafunction");
}


