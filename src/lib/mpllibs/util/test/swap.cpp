// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/swap.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef
    boost::mpl::equal_to<
      mpllibs::util::swap::apply<
        mpllibs::util::pair<boost::mpl::int_<1>, boost::mpl::int_<2> >
      >::type,
      mpllibs::util::pair<boost::mpl::int_<2>, boost::mpl::int_<1> >
    >::type
    Swap_TestSwap;
}

MPLLIBS_ADD_TEST(Swap_TestSwap)

