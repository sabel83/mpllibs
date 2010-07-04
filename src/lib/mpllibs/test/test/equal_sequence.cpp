// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/equal_sequence.h>
#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/int.hpp>

#include <boost/preprocessor/repetition.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("equal_sequence");

  #ifdef DEFINE_INT
    #error DEFINE_INT already defined
  #endif
  #define DEFINE_INT(z, n, unused) typedef boost::mpl::int_<n> Int##n;
    BOOST_PP_REPEAT(4, DEFINE_INT, ~)
  #undef DEFINE_INT
    
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::list<Int0, Int1, Int2, Int3>,
      boost::mpl::list<Int0, Int1, Int2, Int3>
    >
    TestEqualSequences;
  
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::list<Int0, Int1, Int2, Int3>,
      boost::mpl::list<Int0, Int1, Int3, Int2>
    >
    TestNonEqualSequences;
 
  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::list<Int0, Int1, Int2>,
      boost::mpl::list<Int0, Int1, Int2, Int3>
    >
    TestDifferentSize;

  typedef
    mpllibs::test::equal_sequence<
      boost::mpl::list<>,
      boost::mpl::list<>
    >
    TestEmptySequences;
}


MPLLIBS_ADD_TEST(suite, TestEqualSequences)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonEqualSequences)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestDifferentSize)
MPLLIBS_ADD_TEST(suite, TestEmptySequences)

