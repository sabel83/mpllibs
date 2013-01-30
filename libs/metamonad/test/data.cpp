// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/not.hpp>

#include "common.hpp"

namespace
{
  MPLLIBS_DATA(foo, 0, ((con0, 0))((con1, 1))((con2, 1)));

  MPLLIBS_LAZY_METAFUNCTION(lazy_not, (E)) ((boost::mpl::not_<E>));
}

BOOST_AUTO_TEST_CASE(test_data)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::returns;

  using boost::is_same;

  using boost::mpl::equal_to;
  using boost::mpl::int_;

  meta_require<
    is_same<con0, con0::type>
  >(MPLLIBS_HERE, "test_type_of_nullary_constructor");

  meta_require<
    is_same<con1<int>, con1<returns<int> >::type>
  >(MPLLIBS_HERE, "test_type_of_unary_constructor");

  meta_require<
    equal_to<con1<int_<1> >, con1<int_<1> > >
  >(MPLLIBS_HERE, "test_equality");

  meta_require<
    lazy_not<equal_to<con1<int_<1> >, con1<int_<2> > > >
  >(MPLLIBS_HERE, "test_different_constructor_args");

  meta_require<
    lazy_not<equal_to<con1<int_<1> >, con2<int_<1> > > >
  >(MPLLIBS_HERE, "test_different_constructors");

  meta_require<
    equal_to<con0, con0>
  >(MPLLIBS_HERE, "test_nullary_constructor_equality");
}


