// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/syntax.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/assert.hpp>

BOOST_AUTO_TEST_CASE(test_syntax)
{
  using mpllibs::metamonad::syntax;

  using boost::is_same;

  // test_syntax_as_nullary_metafunction
  BOOST_MPL_ASSERT((is_same<syntax<int>, syntax<int>::type>));
}


