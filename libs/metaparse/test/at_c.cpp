// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/impl/at_c.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/char.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_at_c)
{
  using mpllibs::metaparse::impl::at_c;
  using mpllibs::metaparse::string;
  
  using boost::mpl::equal_to;
  using boost::mpl::char_;

  typedef string<'h','e','l','l','o'> hello;

  // test_first_char
  BOOST_MPL_ASSERT((equal_to<char_<'h'>, at_c<hello, 0>::type>));

  // test_middle_char
  BOOST_MPL_ASSERT((equal_to<char_<'l'>, at_c<hello, 2>::type>));

  // test_last_char
  BOOST_MPL_ASSERT((equal_to<char_<'o'>, at_c<hello, 4>::type>));
}


