// Copyright Abel Sinkovics (abel@sinkovics.hu) 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/reject.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/get_position.hpp>

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

BOOST_AUTO_TEST_CASE(test_reject)
{
  using mpllibs::metaparse::reject;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_message;
  using mpllibs::metaparse::get_position;

  using boost::is_same;

  // test_reject_is_metaprogramming_value
  BOOST_MPL_ASSERT((is_same<reject<int, start>, reject<int, start>::type>));

  // test_reject_is_lazy
  BOOST_MPL_ASSERT((
    is_same<reject<int, start>, reject<returns<int>, returns<start> >::type>
  ));

  // test_get_message_of_reject
  BOOST_MPL_ASSERT((is_same<int, get_message<reject<int, start> >::type>));

  // test_get_position_of_reject
  BOOST_MPL_ASSERT((is_same<start, get_position<reject<int, start> >::type>));
}

