// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "my_reverse.h"

#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>

#include <mpllibs/metatest/test.h>

namespace
{
  const mpllibs::metatest::suite_path suite ("my_reverse");

  using namespace boost;
  using namespace mpl;

  typedef vector<> empty;
  typedef vector<char> one;
  typedef vector<char, short, int, long> four;

  typedef vector<long, int, short, char> four_r;

  typedef equal< my_reverse<empty>::type, empty > empty_test;
  typedef equal< my_reverse<one>::type, one > one_test;
  typedef equal< my_reverse<four>::type, four_r > four_test;
}

MPLLIBS_ADD_TEST(suite, empty_test)
MPLLIBS_ADD_TEST(suite, one_test)
MPLLIBS_ADD_TEST(suite, four_test)

