// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/transform_error.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/reject.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/get_position.hpp>

#include <boost/mpl/assert.hpp>

#include <boost/type_traits.hpp>

#include <boost/test/unit_test.hpp>

using mpllibs::metaparse::reject;
using mpllibs::metaparse::get_position;

namespace
{
  struct new_message
  {
    typedef new_message type;
  };

  struct change_message
  {
    typedef change_message type;

    template <class E>
    struct apply : reject<new_message, get_position<E> > {};
  };
}

BOOST_AUTO_TEST_CASE(test_transform_error)
{
  using mpllibs::metaparse::transform_error;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::string;
  using mpllibs::metaparse::lit_c;

  using boost::is_same;

  typedef string<'H','e','l','l','o'> s;

  // test_transform_error_does_not_change_accept
  BOOST_MPL_ASSERT((
    is_same<
      lit_c<'H'>::apply<s, start>::type,
      transform_error<lit_c<'H'>, change_message>::apply<s, start>::type
    >
  ));

  // test_transform_is_called
  BOOST_MPL_ASSERT((
    is_same<
      reject<new_message, start>,
      transform_error<lit_c<'x'>, change_message>::apply<s, start>::type
    >
  ));
}

