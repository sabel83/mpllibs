#ifndef MPLLIBS_TEST_TEST_H
#define MPLLIBS_TEST_TEST_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/test/TestDriver.h>

#ifdef MPLLIBS_ADD_TEST_IMPL
  #error MPLLIBS_ADD_TEST_IMPL already defined
#endif
#define MPLLIBS_ADD_TEST_IMPL(name, result) \
  namespace mpllibs \
  { \
    namespace test \
    { \
      namespace test_cases \
      { \
        namespace \
        { \
          struct name##Executor \
          { \
            name##Executor() \
            { \
              mpllibs::test::TestDriver::instance().runTest<name, result>( \
                #name, \
                mpllibs::test::Location(__FILE__, __LINE__) \
              ); \
            } \
            \
            static name##Executor instance; \
          }; \
          \
          name##Executor name##Executor::instance; \
        } \
      } \
    } \
  } \

#ifdef MPLLIBS_ADD_TEST
  #error MPLLIBS_ADD_TEST already defined
#endif
#define MPLLIBS_ADD_TEST(name) MPLLIBS_ADD_TEST_IMPL(name, true)

#ifdef MPLLIBS_ADD_TEST_TO_FAIL
  #error MPLLIBS_ADD_TEST_TO_FAIL already defined
#endif
#define MPLLIBS_ADD_TEST_TO_FAIL(name) MPLLIBS_ADD_TEST_IMPL(name, false)

#endif

