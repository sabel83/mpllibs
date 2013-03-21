// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/digit_to_int.hpp>

#include "common.hpp"

#include <mpllibs/metamonad/try_c.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_digit_to_int)
{
  using mpllibs::metaparse::util::digit_to_int;
  
  using mpllibs::metamonad::try_c;
  using mpllibs::metamonad::catch_c;
  using mpllibs::metamonad::syntax;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap1;
  using boost::mpl::true_;

  using namespace mpllibs::metamonad::name;

  // test0
  BOOST_MPL_ASSERT((equal_to<apply_wrap1<digit_to_int, char_0>::type, int0>));

  // test9
  BOOST_MPL_ASSERT((equal_to<apply_wrap1<digit_to_int, char_9>::type, int9>));
  
  // test_error
  BOOST_MPL_ASSERT((
    equal_to<
      try_c<apply_wrap1<digit_to_int, char_x>, catch_c<e, true_, int13> >::type,
      int13
    >
  ));
}

