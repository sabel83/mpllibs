// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/find.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/int.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("arithmetic");

  using namespace boost::mpl;
  using boost::is_same;

  typedef list<int,char,long,short,char,long,double,long>::type types;
  typedef list_c<int,1,0,5,1,7,5,0,5> values;

  typedef find<types, short>::type types_iter;
  typedef find< values, integral_c<int,7> >::type values_iter;

  typedef begin<types>::type types_first;
  typedef begin<values>::type values_first;

  typedef is_same< deref<types_iter>::type, short > test_deref_1;
  typedef equal_to< deref<values_iter>::type, int_<7> > test_deref_2;

  //typedef equal_to<
  //      distance<types_first, types_iter>
  //    , int_<3>
  //  > test_distance_1;

  //typedef equal_to<
  //      distance<values_first, types_first>
  //    , int_<4>
  //  > test_distance_2;
}

MPLLIBS_ADD_TEST(suite, test_deref_1)
MPLLIBS_ADD_TEST(suite, test_deref_2)

//MPLLIBS_ADD_TEST(suite, test_distance_1)
//MPLLIBS_ADD_TEST(suite, test_distance_2)

