// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/make_monadic.hpp>
#include <mpllibs/metamonad/already_monadic.hpp>
#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/syntax.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>

#include "common.hpp"

using boost::mpl::plus;

using mpllibs::metamonad::just;

namespace
{
  MPLLIBS_METAFUNCTION(add, (A)(B))
  ((plus<typename A::type, typename B::type>));

  MPLLIBS_METAFUNCTION(make_just, (X)) ((just<X>));
}

BOOST_AUTO_TEST_CASE(test_make_monadic)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::make_monadic;
  using mpllibs::metamonad::already_monadic;
  using mpllibs::metamonad::maybe_tag;
  using mpllibs::metamonad::syntax;

  using boost::mpl::equal_to;

  typedef int11::tag int_tag;
  typedef maybe_tag<int_tag> mt;

  meta_require<
    equal_to<
      just<int13>,
      make_monadic<mt, syntax<already_monadic<just<int13> > > >::type
    >
  >(MPLLIBS_HERE, "test_monadic_values");

  meta_require<
    equal_to<
      int13,
      make_monadic<
        mt,
        syntax<
          add<already_monadic<just<int11> >, already_monadic<just<int2> > >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_metafunction_call");

  meta_require<
    equal_to<
      int13,
      make_monadic<
        mt,
        syntax<
          add<
            already_monadic<make_just<int11> >,
            already_monadic<make_just<int2> >
          >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_nested_function_calls");

  meta_require<
    equal_to<
      int13,
      make_monadic<
        mt,
        syntax<
          plus<already_monadic<just<int11> >, already_monadic<just<int2> > >
        >
      >::type
    >
  >(MPLLIBS_HERE, "test_variadic_metafunction_call");
}



