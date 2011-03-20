// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/compose.h>

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
  const mpllibs::metatest::TestSuite suite("util::compose");

  struct make_pointer
  {
    template <class t>
    struct apply : boost::mpl::identity<t*> {};
  };
  
  struct incr
  {
    template <class t>
    struct apply : boost::mpl::plus<int13, t> {};
  };

  struct double_value
  {
    template <class t>
    struct apply : boost::mpl::times<int2, t> {};
  };

  struct take_first
  {
    template <class a, class b>
    struct apply : boost::mpl::identity<a> {};
  };

  typedef
    boost::is_same<
      boost::mpl::apply<
        mpllibs::metaparse::util::compose<make_pointer, make_pointer>,
        int
      >::type,
      int**
    >
    TestSameFunctionTwice;

  typedef
    boost::is_same<
      boost::mpl::apply<
        mpllibs::metaparse::util::compose<
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
        mpllibs::metaparse::util::compose<double_value, incr>,
        int1
      >::type,
      int28
    >
    TestOrder;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::util::compose<double_value, take_first>,
        int1,
        int3
      >::type,
      int2
    >
    TestTwoArgumentsForTheFirstFunction;
}

MPLLIBS_ADD_TEST(suite, TestSameFunctionTwice)
MPLLIBS_ADD_TEST(suite, TestSameFunctionFiveTimes)
MPLLIBS_ADD_TEST(suite, TestOrder)
MPLLIBS_ADD_TEST(suite, TestTwoArgumentsForTheFirstFunction)


