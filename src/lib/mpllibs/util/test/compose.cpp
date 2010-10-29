// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/compose.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("compose");

  struct make_pointer
  {
    template <class T>
    struct apply : boost::mpl::identity<T*> {};
  };
  
  struct incr
  {
    template <class T>
    struct apply : boost::mpl::plus<int13, T> {};
  };

  struct double_value
  {
    template <class T>
    struct apply : boost::mpl::times<int2, T> {};
  };

  typedef
    boost::is_same<
      boost::mpl::apply<
        mpllibs::util::compose<make_pointer, make_pointer>,
        int
      >::type,
      int**
    >
    TestSameFunctionTwice;

  typedef
    boost::is_same<
      boost::mpl::apply<
        mpllibs::util::compose<
          make_pointer,
          make_pointer,
          make_pointer,
          make_pointer,
          make_pointer
        >,
        int
      >::type,
      int*****
    >
    TestSameFunctionFiveTimes;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::util::compose<double_value, incr>,
        int1
      >::type,
      int28
    >
    TestOrder;

}

MPLLIBS_ADD_TEST(suite, TestSameFunctionTwice)
MPLLIBS_ADD_TEST(suite, TestSameFunctionFiveTimes)
MPLLIBS_ADD_TEST(suite, TestOrder)


