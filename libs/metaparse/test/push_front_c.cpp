// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/push_front_c.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/char.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_push_front_c)
{
  using mpllibs::metaparse::v2::impl::push_front_c;
  using mpllibs::metaparse::string;
  
  using boost::mpl::equal_to;
  using boost::mpl::char_;

  typedef string<'h','e','l','l','o'> hello;

  // test_push_front
  BOOST_MPL_ASSERT((
    equal_to<hello, push_front_c<string<'e','l','l','o'>, 'h'>::type>
  ));

  // test_push_front_to_empty
  BOOST_MPL_ASSERT((equal_to<string<'x'>, push_front_c<string<>, 'x'>::type>));
}


