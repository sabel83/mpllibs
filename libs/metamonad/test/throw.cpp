// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/get_data.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/type_traits/is_same.hpp>

#include "common.hpp"

BOOST_AUTO_TEST_CASE(test_throw_)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::equal_to;
  
  using mpllibs::metamonad::get_data;
  using mpllibs::metamonad::exception_monad;
  using mpllibs::metamonad::throw_;
  using mpllibs::metamonad::do_;
  using mpllibs::metamonad::do_return;

  meta_require<
    equal_to<int13, get_data<throw_<int13> >::type>
  >(MPLLIBS_HERE, "test_get_data");

  
  meta_require<
    equal_to<
      int13,
      get_data<
        do_<exception_monad>::apply<
          throw_<int13>
        >::type
      >::type
    >
  >(MPLLIBS_HERE, "test_monadic_exception");

  meta_require<
    equal_to<
      int11,
      get_data<
        do_<exception_monad>::apply<
          throw_<int11>,
          do_return<int13>
        >::type
      >::type
    >
  >(MPLLIBS_HERE, "test_exception_propagation");
}


