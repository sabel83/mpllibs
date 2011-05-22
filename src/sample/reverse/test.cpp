// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "my_reverse.hpp"

#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>

#include <mpllibs/metatest/test.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("my_reverse");

  using namespace boost;
  using namespace mpl;

  typedef vector<char, short, int, long> types;
  typedef vector<long, int, short, char> reversed;

  typedef equal< my_reverse<types>::type, reversed > test;
}

MPLLIBS_ADD_TEST(suite, test)

