// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/swap.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/int.hpp>

namespace
{
  struct TestSwap :
    mpllibs::test::test_equal<
      mpllibs::util::swap::apply<
        mpllibs::util::pair<boost::mpl::int_<1>, boost::mpl::int_<2> >
      >::type,
      mpllibs::util::pair<boost::mpl::int_<2>, boost::mpl::int_<1> >
    >
  {};
}

