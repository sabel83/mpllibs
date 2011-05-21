// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/comparison.hpp>
#include <boost/mpl/int.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("comparison");

  using namespace boost::mpl;

  typedef int_<0> _0;
  typedef int_<10> _10;

  typedef equal_to <_0, _10> test_equal_to_1;
  typedef equal_to <_10, _0> test_equal_to_2;
  typedef equal_to <_10, _10> test_equal_to_3;

  typedef not_equal_to <_0, _10> test_not_equal_to_1;
  typedef not_equal_to <_10, _0> test_not_equal_to_2;
  typedef not_equal_to <_10, _10> test_not_equal_to_3;

  typedef less <_0, _10> test_less_1;
  typedef less <_10, _0> test_less_2;
  typedef less <_10, _10> test_less_3;

  typedef less_equal <_0, _10> test_less_equal_1;
  typedef less_equal <_10, _0> test_less_equal_2;
  typedef less_equal <_10, _10> test_less_equal_3;

  typedef greater <_0, _10> test_greater_1;
  typedef greater <_10, _0> test_greater_2;
  typedef greater <_10, _10> test_greater_3;

  typedef greater_equal <_0, _10> test_greater_equal_1;
  typedef greater_equal <_10, _0> test_greater_equal_2;
  typedef greater_equal <_10, _10> test_greater_equal_3;
}

MPLLIBS_ADD_TEST_TO_FAIL(suite, test_equal_to_1)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_equal_to_2)
MPLLIBS_ADD_TEST(suite, test_equal_to_3)

MPLLIBS_ADD_TEST(suite, test_not_equal_to_1)
MPLLIBS_ADD_TEST(suite, test_not_equal_to_2)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_not_equal_to_3)

MPLLIBS_ADD_TEST(suite, test_less_1)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_less_2)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_less_3)

MPLLIBS_ADD_TEST(suite, test_less_equal_1)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_less_equal_2)
MPLLIBS_ADD_TEST(suite, test_less_equal_3)

MPLLIBS_ADD_TEST_TO_FAIL(suite, test_greater_1)
MPLLIBS_ADD_TEST(suite, test_greater_2)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_greater_3)

MPLLIBS_ADD_TEST_TO_FAIL(suite, test_greater_equal_1)
MPLLIBS_ADD_TEST(suite, test_greater_equal_2)
MPLLIBS_ADD_TEST(suite, test_greater_equal_3)

