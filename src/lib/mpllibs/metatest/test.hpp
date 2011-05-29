#ifndef MPLLIBS_TEST_TEST_H
#define MPLLIBS_TEST_TEST_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test_driver.hpp>

#ifdef MPLLIBS_ADD_TEST_IMPL
  #error MPLLIBS_ADD_TEST_IMPL already defined
#endif
// We have to use a namespace not used anywhere else to avoid
// test cases being replaced by other classes in the background
#define MPLLIBS_ADD_TEST_IMPL(suite, name, result) \
  namespace mpllibs_test_cases \
  { \
    namespace \
    { \
      struct name##_executor \
      { \
        name##_executor() \
        { \
          mpllibs::metatest::test_driver::run_test<name, result>( \
            (suite), \
            #name, \
            mpllibs::metatest::location(__FILE__, __LINE__) \
          ); \
        } \
        \
        static name##_executor instance; \
      }; \
      \
      name##_executor name##_executor::instance; \
    } \
  }

#ifdef MPLLIBS_ADD_TEST
  #error MPLLIBS_ADD_TEST already defined
#endif
#define MPLLIBS_ADD_TEST(suite, name) \
  MPLLIBS_ADD_TEST_IMPL((suite), name, true)

#ifdef MPLLIBS_ADD_TEST_TO_FAIL
  #error MPLLIBS_ADD_TEST_TO_FAIL already defined
#endif
#define MPLLIBS_ADD_TEST_TO_FAIL(suite, name) \
  MPLLIBS_ADD_TEST_IMPL((suite), name, false)

#endif

