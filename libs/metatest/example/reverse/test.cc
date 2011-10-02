// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
//           Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "my_reverse.hpp"

#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>

#include <boost/mpl/aux_/test.hpp>

MPL_TEST_CASE()
{
  using namespace boost;
  using namespace mpl;

  typedef vector<> empty;
  typedef vector<char> one;
  typedef vector<char, short, int, long> four;

  typedef vector<long, int, short, char> four_r;

  MPL_ASSERT((equal< my_reverse<empty>::type, empty >));
  MPL_ASSERT((equal< my_reverse<one>::type, one >));
  MPL_ASSERT((equal< my_reverse<four>::type, four_r >));

  MPL_ASSERT((equal< my_reverse<empty>::type, one >));
  MPL_ASSERT((equal< my_reverse<one>::type, empty >));
  MPL_ASSERT((equal< my_reverse<four>::type, four >));
}
