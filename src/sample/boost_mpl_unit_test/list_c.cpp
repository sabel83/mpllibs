// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("list_c");

  using namespace boost;
  using namespace mpl;

#if !BOOST_WORKAROUND(BOOST_MSVC,<= 1200)
  namespace testcase_1
  {
    typedef list_c<bool,true>::type l1;
    typedef list_c<bool,false>::type l2;

    typedef is_same< l1::value_type, bool > test_value_type_1;
    typedef is_same< l2::value_type, bool > test_value_type_2;

    typedef equal_to< front<l1>::type, true_ > test_front_1;
    typedef equal_to< front<l2>::type, false_ > test_front_2;

    MPLLIBS_ADD_TEST(suite, test_value_type_1)
    MPLLIBS_ADD_TEST(suite, test_value_type_2)
    MPLLIBS_ADD_TEST(suite, test_front_1)
    MPLLIBS_ADD_TEST(suite, test_front_2)
  }
#endif

  namespace testcase_2
  {
    typedef list_c<int,-1>::type l1;
    typedef list_c<int,0,1>::type l2;
    typedef list_c<int,1,2,3>::type l3;

    typedef is_same<l1::value_type, int> test_value_type_1;
    typedef is_same<l2::value_type, int> test_value_type_2;
    typedef is_same<l3::value_type, int> test_value_type_3;

    typedef equal_to< size<l1>, int_<1> > test_size_1;
    typedef equal_to< size<l2>, int_<2> > test_size_2;
    typedef equal_to< size<l3>, int_<3> > test_size_3;

    typedef equal_to< front<l1>::type, int_<-1> > test_front_1;
    typedef equal_to< front<l2>::type, int_<0> > test_front_2;
    typedef equal_to< front<l3>::type, int_<1> > test_front_3;

    MPLLIBS_ADD_TEST(suite, test_value_type_1)
    MPLLIBS_ADD_TEST(suite, test_value_type_2)
    MPLLIBS_ADD_TEST(suite, test_value_type_3)

    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_size_3)

    MPLLIBS_ADD_TEST(suite, test_front_1)
    MPLLIBS_ADD_TEST(suite, test_front_2)
    MPLLIBS_ADD_TEST(suite, test_front_3)
  }

  namespace testcase_3
  {
    typedef list_c<unsigned,0>::type l1;
    typedef list_c<unsigned,1,2>::type l2;

    typedef is_same<l1::value_type, unsigned> test_value_type_1;
    typedef is_same<l2::value_type, unsigned> test_value_type_2;

    typedef equal_to< size<l1>, int_<1> > test_size_1;
    typedef equal_to< size<l2>, int_<2> > test_size_2;

    typedef equal_to< front<l1>::type, int_<0> > test_front_1;
    typedef equal_to< front<l2>::type, int_<1> > test_front_2;

    MPLLIBS_ADD_TEST(suite, test_value_type_1)
    MPLLIBS_ADD_TEST(suite, test_value_type_2)
    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_front_1)
    MPLLIBS_ADD_TEST(suite, test_front_2)
  }

  namespace testcase_4
  {
    typedef list_c<unsigned,2,1> l2;

    typedef is_same<l2::value_type, unsigned> test_value_type_1;

    typedef begin<l2>::type i1;
    typedef next<i1>::type  i2;
    typedef next<i2>::type  i3;

    typedef equal_to< deref<i1>::type, int_<2> > test_iterator_1;
    typedef equal_to< deref<i2>::type, int_<1> > test_iterator_2;
    typedef is_same<i3, end<l2>::type> test_iterator_3;

    MPLLIBS_ADD_TEST(suite, test_value_type_1)
    MPLLIBS_ADD_TEST(suite, test_iterator_1)
    MPLLIBS_ADD_TEST(suite, test_iterator_2)
    MPLLIBS_ADD_TEST(suite, test_iterator_3)
  }
}

