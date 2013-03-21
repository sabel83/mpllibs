// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/make_monadic_c.hpp>
#include <mpllibs/metamonad/already_monadic.hpp>
#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

using boost::mpl::plus;

using mpllibs::metamonad::just;

namespace
{
  MPLLIBS_METAFUNCTION(add, (A)(B))
  ((plus<typename A::type, typename B::type>));

  MPLLIBS_METAFUNCTION(make_just, (X)) ((just<X>));
}

BOOST_AUTO_TEST_CASE(test_make_monadic_c)
{
  using mpllibs::metamonad::make_monadic_c;
  using mpllibs::metamonad::already_monadic;
  using mpllibs::metamonad::maybe_tag;

  using boost::mpl::equal_to;

  typedef int11::tag int_tag;
  typedef maybe_tag<int_tag> mt;

  // test_monadic_values
  BOOST_MPL_ASSERT((
    equal_to<
      just<int13>,
      make_monadic_c<mt, already_monadic<just<int13> > >::type
    >
  ));

  // test_metafunction_call
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      make_monadic_c<
        mt,
        add<already_monadic<just<int11> >, already_monadic<just<int2> > >
      >::type
    >
  ));

  // test_nested_function_calls
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      make_monadic_c<
        mt,
        add<
          already_monadic<make_just<int11> >,
          already_monadic<make_just<int2> >
        >
      >::type
    >
  ));

  // test_variadic_metafunction_call
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      make_monadic_c<
        mt,
        plus<already_monadic<just<int11> >, already_monadic<just<int2> > >
      >::type
    >
  ));
}



