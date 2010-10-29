// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/equal_sequence.h>
#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/list.hpp>
#include <boost/mpl/int.hpp>

#include <boost/preprocessor/repetition.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("equal_sequence");

  #ifdef DEFINE_INT
    #error DEFINE_INT already defined
  #endif
  #define DEFINE_INT(z, n, unused) typedef boost::mpl::int_<n> Int##n;
    BOOST_PP_REPEAT(4, DEFINE_INT, ~)
  #undef DEFINE_INT
    
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::list<Int0, Int1, Int2, Int3>,
      boost::mpl::list<Int0, Int1, Int2, Int3>
    >
    TestEqualSequences;
  
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::list<Int0, Int1, Int2, Int3>,
      boost::mpl::list<Int0, Int1, Int3, Int2>
    >
    TestNonEqualSequences;
 
  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::list<Int0, Int1, Int2>,
      boost::mpl::list<Int0, Int1, Int2, Int3>
    >
    TestDifferentSize;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::list<>,
      boost::mpl::list<>
    >
    TestEmptySequences;
}


MPLLIBS_ADD_TEST(suite, TestEqualSequences)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestNonEqualSequences)
MPLLIBS_ADD_TEST_TO_FAIL(suite, TestDifferentSize)
MPLLIBS_ADD_TEST(suite, TestEmptySequences)

