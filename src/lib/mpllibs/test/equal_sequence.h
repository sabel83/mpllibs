#ifndef MPLLIBS_TEST_EQUAL_SEQUENCE_H
#define MPLLIBS_TEST_EQUAL_SEQUENCE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/and.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace mpllibs
{
  namespace test
  {
    template <class, class>
    struct equal_sequence;
      
    namespace impl
    {
      template <class l1, class l2>
      struct equal_nonempty_sequence :
        boost::mpl::and_<
          typename boost::mpl::equal_to<
            typename boost::mpl::front<l1>::type,
            typename boost::mpl::front<l2>::type
          >::type,
          typename mpllibs::test::equal_sequence<
            typename boost::mpl::pop_front<l1>::type,
            typename boost::mpl::pop_front<l2>::type
          >::type
        >
      {};
    }
    
    template <class l1, class l2>
    struct equal_sequence :
      boost::mpl::eval_if<
        typename boost::mpl::and_<
          typename boost::mpl::empty<l1>::type,
          typename boost::mpl::empty<l2>::type
        >::type,
        boost::mpl::identity<boost::mpl::true_>,
        boost::mpl::eval_if<
          typename boost::mpl::or_<
            typename boost::mpl::empty<l1>::type,
            typename boost::mpl::empty<l2>::type
          >::type,
          boost::mpl::identity<boost::mpl::false_>,
          mpllibs::test::impl::equal_nonempty_sequence<l1, l2>
        >
      >
    {};
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_TEST_SELF_TEST

#include <mpllibs/test/test.h>
#include <mpllibs/test/test_fail.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/int.hpp>

#include <boost/preprocessor/repetition.hpp>

namespace mpllibs
{
  namespace mpllibs_test_test_equal_sequence
  {
    namespace
    {
      #ifdef DEFINE_INT
        #error DEFINE_INT already defined
      #endif
      #define DEFINE_INT(z, n, unused) typedef boost::mpl::int_<n> Int##n;
        BOOST_PP_REPEAT(4, DEFINE_INT, ~)
      #undef DEFINE_INT
    
      struct TestEqualSequences :
        mpllibs::test::test<
          mpllibs::test::equal_sequence<
            boost::mpl::list<Int0, Int1, Int2, Int3>,
            boost::mpl::list<Int0, Int1, Int2, Int3>
          >::type
        >
      {};
      
      struct TestNonEqualSequences :
        mpllibs::test::test_fail<
          mpllibs::test::equal_sequence<
            boost::mpl::list<Int0, Int1, Int2, Int3>,
            boost::mpl::list<Int0, Int1, Int3, Int2>
          >::type
        >
      {};

      struct TestDifferentSize :
        mpllibs::test::test_fail<
          mpllibs::test::equal_sequence<
            boost::mpl::list<Int0, Int1, Int2>,
            boost::mpl::list<Int0, Int1, Int2, Int3>
          >::type
        >
      {};
      
      struct TestEmptySequences :
        mpllibs::test::test<
          mpllibs::test::equal_sequence<
            boost::mpl::list<>,
            boost::mpl::list<>
          >::type
        >
      {};
    }
  }
}
#endif

#endif
