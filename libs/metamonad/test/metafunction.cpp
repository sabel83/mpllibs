// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/if.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/assert.hpp>

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
  MPLLIBS_METAFUNCTION(double_value, (N)) ((times<N, int_<2> >));

  MPLLIBS_METAFUNCTION(fact, (N))
  ((
    if_<
      less<N, int_<1> >,
      int_<1>,
      lazy<times<fact<minus<N, int_<1> > >, N> >
    >
  ));

  MPLLIBS_METAFUNCTION(mult, (A)(B)) ((times<A, B>));
}

BOOST_AUTO_TEST_CASE(test_metafunction)
{
  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;

  // test_metafunction
  BOOST_MPL_ASSERT((equal_to<int_<6>, double_value<int_<3> >::type>));

  // test_metafunction_with_two_arguments
  BOOST_MPL_ASSERT((equal_to<int_<6>, mult<int_<2>, int_<3> >::type>));

  // test_currying
  BOOST_MPL_ASSERT((
    equal_to<int_<6>, apply_wrap1<mult<int_<2> >::type, int_<3> >::type>
  ));

  // test_using_metafunction_as_metafunction_class
  BOOST_MPL_ASSERT((
    equal_to<int_<6>, apply_wrap2<mult<>, int_<2>, int_<3> >::type>
  ));

  // test_rec_metafunction
  BOOST_MPL_ASSERT((equal_to<int_<6>, fact<int_<3> >::type>));
}


