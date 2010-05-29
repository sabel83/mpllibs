#ifndef MPLLIBS_UTIL_GET_FIRST_H
#define MPLLIBS_UTIL_GET_FIRST_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace util
  {
    struct get_first
    {
      template <class p>
      struct apply
      {
        typedef typename p::first type;
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
  namespace test_mpllibs_util_get_first
  {
    namespace
    {
      struct TestGetFirst :
        mpllibs::test::test_equal<
          mpllibs::util::get_first::apply<
            mpllibs::util::pair<boost::mpl::int_<1>, boost::mpl::int_<2> >
          >::type,
          boost::mpl::int_<1>
        >
      {};
    }
  }
}
#endif

#endif

