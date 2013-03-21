// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/join_string.hpp>

#include <boost/mpl/equal.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_join)
{
  using mpllibs::metaparse::util::join_string;
  
  using boost::mpl::equal;
  using boost::mpl::string;
  using boost::mpl::vector;

  // test_empty
  BOOST_MPL_ASSERT((equal<string<>, join_string<vector<> >::type>));

  // test_single
  BOOST_MPL_ASSERT((
    equal<
      string<'abc'>,
      join_string<vector<string<'abc'> > >::type
    >
  ));

  // test_two
  BOOST_MPL_ASSERT((
    equal<
      string<'abcd', 'ef'>,
      join_string<vector<string<'abc'>, string<'def'> > >::type
    >
  ));

  // test_three
  BOOST_MPL_ASSERT((
    equal<
      string<'abcd', 'efgh'>,
      join_string<vector<string<'abc'>, string<'def'>, string<'gh'> > >::type
    >
  ));
}

