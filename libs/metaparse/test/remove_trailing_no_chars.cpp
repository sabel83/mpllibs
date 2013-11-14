// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/impl/remove_trailing_no_chars.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/char.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_remove_trailing_no_chars)
{
  using mpllibs::metaparse::impl::remove_trailing_no_chars;
  using mpllibs::metaparse::string;
  
  using boost::mpl::equal_to;
  using boost::mpl::char_;

  typedef string<'h','e','l','l','o'> hello;

  // test_hello
  BOOST_MPL_ASSERT((equal_to<hello, remove_trailing_no_chars<hello>::type>));

  // test_twice
  BOOST_MPL_ASSERT((
    equal_to<
      hello,
      remove_trailing_no_chars<remove_trailing_no_chars<hello>::type>::type
    >
  ));

  // test_hello_with_no_chars
  BOOST_MPL_ASSERT((
    equal_to<
      hello,
      remove_trailing_no_chars<
        string<'h','e','l','l','o', MPLLIBS_NO_CHAR, MPLLIBS_NO_CHAR>
      >::type
    >
  ));

  // test_empty
  BOOST_MPL_ASSERT((
    equal_to<string<>, remove_trailing_no_chars<string<> >::type>
  ));

  // test_empty_with_no_chars
  BOOST_MPL_ASSERT((
    equal_to<
      string<>,
      remove_trailing_no_chars<string<MPLLIBS_NO_CHAR, MPLLIBS_NO_CHAR> >::type
    >
  ));
}


