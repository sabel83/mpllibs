// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("list");

  using namespace boost::mpl;
  using boost::is_same;

  typedef list0<> l0;
  typedef list1<char> l1;
  typedef list2<char,long> l2;
  typedef list9<char,char,char,char,char,char,char,char,char> l9;

  typedef equal_to< size<l0>, int_<0> > test_size_1;
  typedef equal_to< size<l1>, int_<1> > test_size_2;
  typedef equal_to< size<l2>, int_<2> > test_size_3;
  typedef equal_to< size<l9>, int_<9> > test_size_4;

  typedef empty<l0> test_empty_1;
  typedef empty<l1> test_empty_2;
  typedef empty<l2> test_empty_3;
  typedef empty<l9> test_empty_4;

  typedef is_same<front<l1>::type, char> test_front_1;
  typedef is_same<front<l2>::type, char> test_front_2;
  typedef is_same<front<l9>::type, char> test_front_3;

  typedef is_same<
        deref< begin<l2>::type >::type
      , char
    > test_iter_1;

  typedef is_same<
        deref< next<begin<l2>::type>::type >::type
      , long
    > test_iter_2;

  typedef is_same<
        next< next<begin<l2>::type>::type >::type
      , end<l2>::type
    > test_iter_3;

  typedef is_same<
        front<
            push_front<l0, char>::type
        >::type
      , char
    > test_push_front_1;

  typedef is_same<
        front<
            push_front<
                push_front<l0, char>::type
              , long
            >::type
        >::type
      , long
    > test_push_front_2;
}

MPLLIBS_ADD_TEST(suite, test_size_1)
MPLLIBS_ADD_TEST(suite, test_size_2)
MPLLIBS_ADD_TEST(suite, test_size_3)
MPLLIBS_ADD_TEST(suite, test_size_4)

MPLLIBS_ADD_TEST(suite, test_empty_1)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_empty_2)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_empty_3)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test_empty_4)

MPLLIBS_ADD_TEST(suite, test_front_1)
MPLLIBS_ADD_TEST(suite, test_front_2)
MPLLIBS_ADD_TEST(suite, test_front_3)

MPLLIBS_ADD_TEST(suite, test_iter_1)
MPLLIBS_ADD_TEST(suite, test_iter_2)
MPLLIBS_ADD_TEST(suite, test_iter_3)

MPLLIBS_ADD_TEST(suite, test_push_front_1)
MPLLIBS_ADD_TEST(suite, test_push_front_2)

