// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("vector_c");

  using namespace boost::mpl;
  using boost::is_same;

#if !BOOST_WORKAROUND(BOOST_MSVC, <=1200)
  namespace testcase_1
  {
    typedef is_same< vector_c<bool, true>::value_type, bool > t1;
    typedef is_same< vector_c<bool, false>::value_type, bool > t2;
    typedef equal_to< front< vector_c<bool, true> >::type, true_ > t3;
    typedef equal_to< front< vector_c<bool, false> >::type, false_ > t4;

    MPLLIBS_ADD_TEST (suite, t1)
    MPLLIBS_ADD_TEST (suite, t2)
    MPLLIBS_ADD_TEST (suite, t3)
    MPLLIBS_ADD_TEST (suite, t4)
  }
#endif

  namespace testcase_2
  {
    typedef vector_c<int,-1> v1;
    typedef vector_c<int,0,1> v2;
    typedef vector_c<int,1,2,3> v3;

    typedef is_same<v1::value_type, int> test_value_type_1;
    typedef is_same<v2::value_type, int> test_value_type_2;
    typedef is_same<v3::value_type, int> test_value_type_3;

    typedef equal_to< size<v1>, int_<1> > test_size_1;
    typedef equal_to< size<v2>, int_<2> > test_size_2;
    typedef equal_to< size<v3>, int_<3> > test_size_3;

    typedef equal_to< front<v1>::type, int_<-1> > test_front_1;
    typedef equal_to< front<v2>::type, int_<0> > test_front_2;
    typedef equal_to< front<v3>::type, int_<1> > test_front_3;

    MPLLIBS_ADD_TEST (suite, test_value_type_1)
    MPLLIBS_ADD_TEST (suite, test_value_type_2)
    MPLLIBS_ADD_TEST (suite, test_value_type_3)

    MPLLIBS_ADD_TEST (suite, test_size_1)
    MPLLIBS_ADD_TEST (suite, test_size_2)
    MPLLIBS_ADD_TEST (suite, test_size_3)

    MPLLIBS_ADD_TEST (suite, test_front_1)
    MPLLIBS_ADD_TEST (suite, test_front_2)
    MPLLIBS_ADD_TEST (suite, test_front_3)
  }

  namespace testcase_3
  {
    typedef vector_c<unsigned,0> v1;
    typedef vector_c<unsigned,1,2> v2;

    typedef is_same< v1::value_type, unsigned > test_value_type_1;
    typedef is_same< v2::value_type, unsigned > test_value_type_2;

    typedef equal_to< size<v1>, int_<1> > test_size_1;
    typedef equal_to< size<v2>, int_<2> > test_size_2;

    typedef equal_to< front<v1>::type, int_<0> > test_front_1;
    typedef equal_to< front<v2>::type, int_<1> > test_front_2;

    MPLLIBS_ADD_TEST (suite, test_value_type_1)
    MPLLIBS_ADD_TEST (suite, test_value_type_2)

    MPLLIBS_ADD_TEST (suite, test_size_1)
    MPLLIBS_ADD_TEST (suite, test_size_2)

    MPLLIBS_ADD_TEST (suite, test_front_1)
    MPLLIBS_ADD_TEST (suite, test_front_2)
  }
}

