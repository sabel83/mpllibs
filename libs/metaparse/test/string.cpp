// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/equal.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

#ifndef BOOST_NO_CONSTEXPR

BOOST_AUTO_TEST_CASE(test_string)
{
  using boost::mpl::equal;

  // test_empty_string
  BOOST_MPL_ASSERT((equal<MPLLIBS_STRING(""), boost::mpl::string<> >));

  // test_string_creation
  BOOST_MPL_ASSERT((
    equal<MPLLIBS_STRING("hello"), boost::mpl::string<'h','e','l','l','o'> >
  ));
}

#endif

