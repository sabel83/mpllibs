// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

// Bad metafunction: no "type"
template <class t>
struct bad {};

// Bad metafunction for a test case: no "type::value"
template <class t>
struct bad2
{
  struct type {};
};

namespace
{
  const mpllibs::metatest::TestSuite suite("example_failure");

  typedef bad<int> TestNoType;

  typedef bad2<int> TestNoTypeValue;

  typedef boost::mpl::false_ TestFail;
}

MPLLIBS_ADD_TEST(suite, TestNoType)
MPLLIBS_ADD_TEST(suite, TestNoTypeValue)
MPLLIBS_ADD_TEST(suite, TestFail)


