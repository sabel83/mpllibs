// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/deque.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/pop_back.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("deque");

  using namespace boost;
  using namespace mpl;

  namespace testcase_2
  {
    typedef deque<> d0;
    typedef deque<char> d1;
    typedef deque<char,long> d2;
    typedef deque<char,char,char,char,char,char,char,char,int> d9;

    typedef equal_to< size<d0>, int_<0> > test_size_1;
    typedef equal_to< size<d1>, int_<1> > test_size_2;
    typedef equal_to< size<d2>, int_<2> > test_size_3;
    typedef equal_to< size<d9>, int_<9> > test_size_4;

    typedef empty<d0> test_empty_1;
    typedef not_< empty<d1> > test_empty_2;
    typedef not_< empty<d2> > test_empty_3;
    typedef not_< empty<d9> > test_empty_4;

    typedef is_same< front<d1>::type, char > test_front_1;
    typedef is_same< front<d2>::type, char > test_front_2;
    typedef is_same< front<d9>::type, char > test_front_3;

    typedef is_same< back<d1>::type, char > test_back_1;
    typedef is_same< back<d2>::type, long > test_back_2;
    typedef is_same< back<d9>::type, int > test_back_3;

    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_size_3)
    MPLLIBS_ADD_TEST(suite, test_size_4)
    MPLLIBS_ADD_TEST(suite, test_empty_1)
    MPLLIBS_ADD_TEST(suite, test_empty_2)
    MPLLIBS_ADD_TEST(suite, test_empty_3)
    MPLLIBS_ADD_TEST(suite, test_empty_4)
    MPLLIBS_ADD_TEST(suite, test_front_1)
    MPLLIBS_ADD_TEST(suite, test_front_2)
    MPLLIBS_ADD_TEST(suite, test_front_3)
    MPLLIBS_ADD_TEST(suite, test_back_1)
    MPLLIBS_ADD_TEST(suite, test_back_2)
    MPLLIBS_ADD_TEST(suite, test_back_3)
  }

  namespace testcase_1
  {
    typedef deque<char,long> d2;

    typedef begin<d2>::type i1;
    typedef next<i1>::type  i2;
    typedef next<i2>::type  i3;

    typedef is_same< deref<i1>::type, char > test_iter_1;
    typedef is_same< deref<i2>::type, long > test_iter_2;
    typedef is_same< i3, end<d2>::type > test_iter_3;

    MPLLIBS_ADD_TEST(suite, test_iter_1)
    MPLLIBS_ADD_TEST(suite, test_iter_2)
    MPLLIBS_ADD_TEST(suite, test_iter_3)
  }

  namespace testcase_3
  {
    typedef deque<> d0;
    typedef push_back<d0,int>::type d1;
    typedef push_front<d1,char>::type d2;
    typedef push_back<d2,long>::type d3;

    typedef is_same< back<d1>::type, int > test_push_1;
    typedef is_same< back<d2>::type, int > test_push_2;
    typedef is_same< front<d2>::type, char > test_push_3;
    typedef is_same< back<d3>::type, long > test_push_4;

    MPLLIBS_ADD_TEST(suite, test_push_1)
    MPLLIBS_ADD_TEST(suite, test_push_2)
    MPLLIBS_ADD_TEST(suite, test_push_3)
    MPLLIBS_ADD_TEST(suite, test_push_4)
  }
}

