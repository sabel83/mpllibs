#ifndef MPLLIBS_UTIL_SWAP_H
#define MPLLIBS_UTIL_SWAP_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/pair.h>

namespace mpllibs
{
  namespace util
  {
    struct swap
    {
      template <class p>
      struct apply
      {
        typedef
          mpllibs::util::pair<typename p::second, typename p::first>
          type;
      };
    };
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_UTIL_SELF_TEST

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace test_mpllibs_util_swap
  {
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
  }
}
#endif

#endif

