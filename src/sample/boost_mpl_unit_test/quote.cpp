// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/quote.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("quote");

  using namespace boost::mpl;
  using boost::is_same;

  template <typename T>
  struct f1
  {
    typedef T type;
  };

  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  struct f5
  {
#if defined(BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS)
    typedef f5 type;
#endif
  };

  typedef quote1<f1>::apply<int>::type q1;
  typedef quote5<f5>::apply<char,short,int,long,float>::type q5;

  typedef is_same <q1, int> t1;
  typedef is_same <q5, f5<char,short,int,long,float> > t5;
}

MPLLIBS_ADD_TEST (suite, t1)
MPLLIBS_ADD_TEST (suite, t5)

