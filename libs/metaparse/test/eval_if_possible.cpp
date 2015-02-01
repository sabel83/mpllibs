// Copyright Abel Sinkovics (abel@sinkovics.hu) 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/eval_if_possible.hpp>

#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  template <class T>
  struct returns
  {
    typedef T type;
  };
}

BOOST_AUTO_TEST_CASE(test_eval_if_possible)
{
  using mpllibs::metaparse::v2::impl::eval_if_possible;

  using boost::is_same;

  // test_int_is_not_evaluated
  BOOST_MPL_ASSERT((is_same<int, eval_if_possible<int>::type>));

  // test_returns_is_evaluated
  BOOST_MPL_ASSERT((is_same<int, eval_if_possible<returns<int> >::type>));

  // test_returns_is_evaluated_only_once
  BOOST_MPL_ASSERT((
    is_same<returns<int>, eval_if_possible<returns<returns<int> > >::type>
  ));
}

