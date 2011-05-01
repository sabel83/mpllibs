// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "my_reverse.h"

#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>

#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
  typedef vector<char, short, int, long> types;
  typedef vector<long, int, short, char> reversed;

  MPL_ASSERT(( equal< my_reverse<types>::type, reversed > ));
}

