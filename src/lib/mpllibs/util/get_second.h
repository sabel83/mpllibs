#ifndef MPLLIBS_UTIL_GET_SECOND_H
#define MPLLIBS_UTIL_GET_SECOND_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace util
  {
    struct get_second
    {
      template <class p>
      struct apply
      {
        typedef typename p::second type;
      };
    };
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_UTIL_SELF_TEST

#include <mpllibs/util/pair.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace test_mpllibs_util_get_second
  {
    namespace
    {
      struct TestGetSecond :
        mpllibs::test::test_equal<
          mpllibs::util::get_second::apply<
            mpllibs::util::pair<boost::mpl::int_<1>, boost::mpl::int_<2> >
          >::type,
          boost::mpl::int_<2>
        >
      {};
    }
  }
}
#endif

#endif

