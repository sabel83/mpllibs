// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/type_traits/is_same.hpp>

using namespace boost;
using namespace mpl;

namespace
{
  const mpllibs::metatest::test_suite suite ("ugly");

  namespace testcase_1
  {
    typedef front< vector<char,short,int> > f;

    typedef is_same<f, char> test1;
    MPLLIBS_ADD_TEST(suite, test1)
  }

  namespace testcase_2
  {
    typedef size< vector<char,short,int> > s;

    typedef equal_to< s, int_<3> > test2;
    MPLLIBS_ADD_TEST(suite, test2)
  }

  namespace testcase_3
  {
    typedef vector<char, short> v1;
    typedef pop_front<v1>::type v2;

    typedef is_same< v2, vector<short> > test3;
    MPLLIBS_ADD_TEST(suite, test3)
  }
}

