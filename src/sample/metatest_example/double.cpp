// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/times.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

// Metafunction to test
template <class t>
struct double_ : boost::mpl::times<t, boost::mpl::int_<2> > {};

namespace
{
  const mpllibs::metatest::TestSuite suite("example");

  typedef
    boost::mpl::equal_to<
      double_<boost::mpl::int_<13> >::type,
      boost::mpl::int_<26>
    >
    TestSuccess;
}

MPLLIBS_ADD_TEST(suite, TestSuccess)


