// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/vector.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/aux_/test.hpp>

using namespace boost;
using namespace mpl;

MPL_TEST_CASE()
{
  typedef front< vector<char,short,int> > f;

  MPL_ASSERT(( is_same<f,char> ));
}

MPL_TEST_CASE()
{
  typedef size< vector<char,short,int> > s;

  MPL_ASSERT_RELATION(s, ==, 3);
}

MPL_TEST_CASE()
{
  typedef vector<char,short> v1;
  typedef pop_front<v1>::type v2;

  MPL_ASSERT(( is_same< v2, vector<short> > ));
}

