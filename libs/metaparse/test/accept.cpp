// Copyright Abel Sinkovics (abel@sinkovics.hu) 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>

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

BOOST_AUTO_TEST_CASE(test_accept)
{
  using mpllibs::metaparse::accept;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::string;
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::get_position;
  using mpllibs::metaparse::get_remaining;

  using boost::is_same;

  typedef string<'H','e','l','l','o'> s;

  // test_accept_is_metaprogramming_value
  BOOST_MPL_ASSERT((
    is_same<accept<int, s, start>, accept<int, s, start>::type>
  ));

  // test_accept_is_lazy
  BOOST_MPL_ASSERT((
    is_same<
      accept<int, s, start>,
      accept<returns<int>, returns<s>, returns<start> >::type
    >
  ));

  // test_get_result_of_accept
  BOOST_MPL_ASSERT((is_same<int, get_result<accept<int, s, start> >::type>));

  // test_get_remaining_of_accept
  BOOST_MPL_ASSERT((is_same<s, get_remaining<accept<int, s, start> >::type>));

  // test_get_position_of_accept
  BOOST_MPL_ASSERT((
    is_same<start, get_position<accept<int, s, start> >::type>
  ));
}

