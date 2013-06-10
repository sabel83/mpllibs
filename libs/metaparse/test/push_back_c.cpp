// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/impl/push_back_c.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/char.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_push_back_c)
{
  using mpllibs::metaparse::impl::push_back_c;
  using mpllibs::metaparse::string;
  
  using boost::mpl::equal_to;
  using boost::mpl::char_;

  typedef string<'h','e','l','l','o'> hello;

  // test_push_back
  BOOST_MPL_ASSERT((
    equal_to<hello, push_back_c<string<'h','e','l','l'>, 'o'>::type>
  ));

  // test_push_back_to_empty
  BOOST_MPL_ASSERT((equal_to<string<'x'>, push_back_c<string<>, 'x'>::type>));
}


