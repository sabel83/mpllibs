// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/assert.hpp>

using mpllibs::metamonad::returns;

using boost::is_same;

namespace
{
  MPLLIBS_METAFUNCTION(returns_double, (A)(B)(C)) ((returns<double>));
  MPLLIBS_METAFUNCTION(is_double, (T)) ((is_same<T, double>));
}

BOOST_AUTO_TEST_CASE(test_lazy_protect_args)
{
  using mpllibs::metamonad::lazy;
  using mpllibs::metamonad::lazy_protect_args;
  
  // test_args_are_not_evaluated
  BOOST_MPL_ASSERT((
    lazy<is_double<lazy_protect_args<returns_double<int, int, int> > > >
  ));

  // test_outside_of_lazy
  BOOST_MPL_ASSERT((
    is_same<lazy_protect_args<returns_double<int, int, int> >::type, double>
  ));
}


