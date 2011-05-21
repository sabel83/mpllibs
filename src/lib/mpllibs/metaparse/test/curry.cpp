// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/curry.h>

#include "common.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/identity.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::curry0;
using mpllibs::metaparse::util::curry2;

using boost::mpl::identity;
using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const suite_path suite = suite_path("util")("curry");
  
  template <class A, class B>
  struct get_first : identity<A> {};
  
  template <class A, class B>
  struct get_second : identity<B> {};
  
  struct nullary_metafunction : identity<int13> {};
  
  typedef
    equal_to<apply<apply<curry2<get_first>, int11>::type, int13>::type, int11>
    test_currying_first_argument;

  typedef
    equal_to<apply<apply<curry2<get_second>, int11>::type, int13>::type, int13>
    test_currying_second_argument;

  typedef equal_to<curry0<nullary_metafunction>::type, int13> test_nullary;
}

MPLLIBS_ADD_TEST(suite, test_currying_first_argument)
MPLLIBS_ADD_TEST(suite, test_currying_second_argument)
MPLLIBS_ADD_TEST(suite, test_nullary)

