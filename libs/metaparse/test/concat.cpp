// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/impl/concat.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/char.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_concat)
{
  using mpllibs::metaparse::impl::concat;
  using mpllibs::metaparse::string;
  
  using boost::mpl::equal_to;

  typedef string<> empty;
  typedef string<'h','e','l','l','o'> hello;

  // test_empty_empty
  BOOST_MPL_ASSERT((equal_to<empty, concat<empty, empty>::type>));

  // test_empty_hello
  BOOST_MPL_ASSERT((equal_to<hello, concat<empty, hello>::type>));

  // test_hello_empty
  BOOST_MPL_ASSERT((equal_to<hello, concat<hello, empty>::type>));

  // test_hello_hello
  BOOST_MPL_ASSERT((
    equal_to<
      string<'h','e','l','l','o','h','e','l','l','o'>,
      concat<hello, hello>::type
    >
  ));
}


