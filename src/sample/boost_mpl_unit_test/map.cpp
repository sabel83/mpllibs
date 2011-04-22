// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/map.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/order.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("map");

  using namespace boost::mpl;
  using boost::is_same;

  struct UDT {};
  struct incomplete;

  namespace testcase_1
  {

    typedef map2<
          pair<int, unsigned>
        , pair<char, unsigned char>
      > m_;

    typedef erase_key<m_, char>::type m;

    typedef equal_to< size<m>, int_<1> > test_erase_1;
    typedef not_< empty<m> > test_erase_2;
    typedef is_same< clear<m>::type, map0<> > test_clear_1;

    typedef is_same< at<m_, int>::type, unsigned > test_at_1;
    typedef is_same< at<m, char >::type, void_ > test_at_2;
    typedef contains< m, pair<int, unsigned> > test_contains_1;
    typedef not_< contains<m, pair<int, int> > > test_contains_2;
    typedef not_< contains<m, pair<char, unsigned char> > > test_contains_3;

    typedef not_< has_key<m, char> > test_has_key_1;
    typedef has_key<m, int> test_has_key_2;
    typedef not_< is_same< order<m, int>::type, void_ > > test_order_1;
    typedef is_same< order<m, char>::type, void_ > test_order_2;

    typedef begin<m>::type first;
    typedef end<m>::type last;

    typedef is_same< deref<first>::type, pair<int, unsigned> > test_deref_1;
    typedef is_same< next<first>::type, last > test_next_1;

    typedef insert<m, pair<char, long> >::type m2;

    typedef equal_to< size<m2>, int_<2> > test_size_1;
    typedef not_< empty<m2> > test_empty_1;
    typedef is_same< clear<m2>::type, map0<> > test_clear_2;
    typedef is_same< at<m2, int>::type, unsigned > test_at_3;
    typedef is_same< at<m2, char>::type, long> test_at_4;

    typedef contains< m2, pair<int, unsigned> > test_contains_4;
    typedef not_< contains<m2, pair<int, int> > > test_contains_5;
    typedef not_< contains<m2, pair<char, unsigned char> > > test_contains_6;
    typedef contains< m2, pair<char, long> > test_contains_7;

    typedef has_key<m2, char> test_has_key_3;
    typedef not_< has_key<m2, long> > test_has_key_4;
    typedef not_< is_same<order<m2, int>::type, void_> > test_order_3;
    typedef not_< is_same<order<m2, char>::type, void_> > test_order_4;
    typedef not_< is_same<order<m2, char>::type, order<m2, int>::type > > test_order_5;

    typedef begin<m2>::type first2;
    typedef end<m2>::type last2;

    typedef is_same< deref<first2>::type, pair<int, unsigned> > test_deref_2;

    typedef next<first2>::type iter;
    typedef is_same< deref<iter>::type, pair<char, long> > test_deref_3;
    typedef is_same< next<iter>::type, last2 > test_next_2;

    typedef insert<m2, pair<int, unsigned> >::type s2_1;
    typedef is_same<m2, s2_1> test_insert_1;

    typedef insert<m2, pair<long, unsigned> >::type m3;
    typedef equal_to< size<m3>, int_<3> > test_size_2;
    typedef has_key<m3, long> test_has_key_5;
    typedef has_key<m3, int> test_has_key_6;
    typedef has_key<m3, char> test_has_key_7;
    typedef contains<m3, pair<long, unsigned> > test_contains_8;
    typedef contains<m3, pair<int, unsigned> > test_contains_9;

    typedef insert<m, pair<char, long> >::type m1;
    typedef equal_to< size<m1>, int_<2> > test_size_3;
    typedef is_same< at<m1, int>::type, unsigned> test_at_5;
    typedef is_same< at<m1, char>::type, long> test_at_6;

    typedef contains<m1, pair<int, unsigned> > test_contains_10;
    typedef not_< contains<m1, pair<int, int> > > test_contains_11;
    typedef not_< contains<m1, pair<char, unsigned char> > > test_contains_12;
    typedef contains<m1, pair<char, long> > test_contains_13;

    typedef is_same<m1, m2> test_insert_2;

    typedef erase_key<m1, char>::type m_1;
    typedef is_same<m, m_1> test_erase_key_1;
    typedef equal_to< size<m_1>, int_<1> > test_size_4;
    typedef is_same< at<m_1, char>::type, void_> test_at_7;
    typedef is_same< at<m_1, int>::type, unsigned> test_at_8;

    typedef erase_key<m3, char>::type m2_1;
    typedef equal_to< size<m2_1>, int_<2> > test_size_5;
    typedef is_same< at<m2_1, char>::type, void_> test_at_9;
    typedef is_same< at<m2_1, int>::type, unsigned> test_at_10;
    typedef is_same< at<m2_1, long>::type, unsigned> test_at_11;

    MPLLIBS_ADD_TEST(suite, test_erase_1)
    MPLLIBS_ADD_TEST(suite, test_erase_2)
    MPLLIBS_ADD_TEST(suite, test_clear_1)
    MPLLIBS_ADD_TEST(suite, test_at_1)
    MPLLIBS_ADD_TEST(suite, test_at_2)
    MPLLIBS_ADD_TEST(suite, test_contains_1)
    MPLLIBS_ADD_TEST(suite, test_contains_2)
    MPLLIBS_ADD_TEST(suite, test_contains_3)
    MPLLIBS_ADD_TEST(suite, test_has_key_1)
    MPLLIBS_ADD_TEST(suite, test_has_key_2)
    MPLLIBS_ADD_TEST(suite, test_order_1)
    MPLLIBS_ADD_TEST(suite, test_order_2)
    MPLLIBS_ADD_TEST(suite, test_deref_1)
    MPLLIBS_ADD_TEST(suite, test_next_1)
    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_empty_1)
    MPLLIBS_ADD_TEST(suite, test_clear_2)
    MPLLIBS_ADD_TEST(suite, test_at_3)
    MPLLIBS_ADD_TEST(suite, test_at_4)
    MPLLIBS_ADD_TEST(suite, test_contains_4)
    MPLLIBS_ADD_TEST(suite, test_contains_5)
    MPLLIBS_ADD_TEST(suite, test_contains_6)
    MPLLIBS_ADD_TEST(suite, test_contains_7)
    MPLLIBS_ADD_TEST(suite, test_has_key_3)
    MPLLIBS_ADD_TEST(suite, test_has_key_4)
    MPLLIBS_ADD_TEST(suite, test_order_3)
    MPLLIBS_ADD_TEST(suite, test_order_4)
    MPLLIBS_ADD_TEST(suite, test_order_5)
    MPLLIBS_ADD_TEST(suite, test_deref_2)
    MPLLIBS_ADD_TEST(suite, test_deref_3)
    MPLLIBS_ADD_TEST(suite, test_next_2)
    MPLLIBS_ADD_TEST(suite, test_insert_1)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_has_key_5)
    MPLLIBS_ADD_TEST(suite, test_has_key_6)
    MPLLIBS_ADD_TEST(suite, test_has_key_7)
    MPLLIBS_ADD_TEST(suite, test_contains_8)
    MPLLIBS_ADD_TEST(suite, test_contains_9)
    MPLLIBS_ADD_TEST(suite, test_size_3)
    MPLLIBS_ADD_TEST(suite, test_at_5)
    MPLLIBS_ADD_TEST(suite, test_at_6)
    MPLLIBS_ADD_TEST(suite, test_contains_10)
    MPLLIBS_ADD_TEST(suite, test_contains_11)
    MPLLIBS_ADD_TEST(suite, test_contains_12)
    MPLLIBS_ADD_TEST(suite, test_contains_13)
    MPLLIBS_ADD_TEST(suite, test_insert_2)
    MPLLIBS_ADD_TEST(suite, test_erase_key_1)
    MPLLIBS_ADD_TEST(suite, test_size_4)
    MPLLIBS_ADD_TEST(suite, test_at_7)
    MPLLIBS_ADD_TEST(suite, test_at_8)
    MPLLIBS_ADD_TEST(suite, test_size_5)
    MPLLIBS_ADD_TEST(suite, test_at_9)
    MPLLIBS_ADD_TEST(suite, test_at_10)
    MPLLIBS_ADD_TEST(suite, test_at_11)
  }

  namespace testcase_2
  {
    typedef map0<> m;

    typedef equal_to< size<m>, int_<0> > test_size_1;
    typedef empty<m> test_empty_1;

    typedef is_same< clear<m>::type, map0<> > test_clear_1;
    typedef is_same< at<m, char>::type, void_> test_at_1;

    typedef not_< has_key<m, char>::type > test_has_key_1;
    typedef not_< has_key<m, int>::type > test_has_key_2;
    typedef not_< has_key<m, UDT>::type > test_has_key_3;
    typedef not_< has_key<m, incomplete>::type > test_has_key_4;

    typedef not_< has_key<m, char const>::type > test_has_key_5;
    typedef not_< has_key<m, int const>::type > test_has_key_6;
    typedef not_< has_key<m, UDT const>::type > test_has_key_7;
    typedef not_< has_key<m, incomplete const>::type > test_has_key_8;

    typedef not_< has_key<m, int *>::type > test_has_key_9;
    typedef not_< has_key<m, UDT *>::type > test_has_key_10;
    typedef not_< has_key<m, incomplete *>::type > test_has_key_11;

    typedef not_< has_key<m, int &>::type > test_has_key_12;
    typedef not_< has_key<m, UDT &>::type > test_has_key_13;
    typedef not_< has_key<m, incomplete &>::type > test_has_key_14;

    typedef insert<m, pair<char, int> >::type m1;
    typedef equal_to< size<m1>, int_<1> > test_size_2;
    typedef is_same< at<m1, char>::type, int > test_at_2;

    typedef erase_key<m, char>::type m0_1;
    typedef equal_to< size<m0_1>, int_<0> > test_size_3;
    typedef is_same< at<m0_1, char>::type, void_> test_at_3;

    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_empty_1)
    MPLLIBS_ADD_TEST(suite, test_clear_1)
    MPLLIBS_ADD_TEST(suite, test_at_1)
    MPLLIBS_ADD_TEST(suite, test_has_key_1)
    MPLLIBS_ADD_TEST(suite, test_has_key_2)
    MPLLIBS_ADD_TEST(suite, test_has_key_3)
    MPLLIBS_ADD_TEST(suite, test_has_key_4)
    MPLLIBS_ADD_TEST(suite, test_has_key_5)
    MPLLIBS_ADD_TEST(suite, test_has_key_6)
    MPLLIBS_ADD_TEST(suite, test_has_key_7)
    MPLLIBS_ADD_TEST(suite, test_has_key_8)
    MPLLIBS_ADD_TEST(suite, test_has_key_9)
    MPLLIBS_ADD_TEST(suite, test_has_key_10)
    MPLLIBS_ADD_TEST(suite, test_has_key_11)
    MPLLIBS_ADD_TEST(suite, test_has_key_12)
    MPLLIBS_ADD_TEST(suite, test_has_key_13)
    MPLLIBS_ADD_TEST(suite, test_has_key_14)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_at_2)
    MPLLIBS_ADD_TEST(suite, test_size_3)
    MPLLIBS_ADD_TEST(suite, test_at_3)
  }

  namespace testcase_3
  {
    typedef map< pair<int, int *> > map_of_1_pair;
    typedef begin<map_of_1_pair>::type iter_to_1_pair;

    typedef is_same<
          deref<iter_to_1_pair>::type
        , pair<int, int *>
      > test_deref;

    typedef map<
          pair<int, int*>
        , pair<long, long*>
        , pair<char, char*>
      > mymap;

    typedef equal_to< size<mymap>, int_<3> > test_size;

    typedef not_<
          is_same<
              find<mymap, pair<int, int*> >::type
            , end<mymap>::type
          >
      > test_find_1;

    typedef not_<
          is_same<
              find<mymap, pair<long, long*> >::type
            , end<mymap>::type
          >
      > test_find_2;

    typedef not_<
          is_same<
              find<mymap, pair<char, char*> >::type
            , end<mymap>::type
          >
      > test_find_3;

    typedef is_same<
          find<mymap, int >::type
        , end<mymap>::type
      > test_find_4;

    MPLLIBS_ADD_TEST(suite, test_deref)
    MPLLIBS_ADD_TEST(suite, test_size)
    MPLLIBS_ADD_TEST(suite, test_find_1)
    MPLLIBS_ADD_TEST(suite, test_find_2)
    MPLLIBS_ADD_TEST(suite, test_find_3)
    MPLLIBS_ADD_TEST(suite, test_find_4)
  }

  namespace testcase_4
  {
    typedef erase_key<
          map< pair<char, double>, pair<int, float> >
        , char
      >::type int_to_float_map;

    typedef insert<
          int_to_float_map
        , pair<char, long>
      >::type with_char_too;

    typedef is_same< at<with_char_too, char>::type, long > test_at;

    MPLLIBS_ADD_TEST(suite, test_at)
  }
}

