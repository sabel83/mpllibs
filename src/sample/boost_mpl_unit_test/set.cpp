// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/set.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/insert.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/erase_key.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/order.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("set");

  using namespace boost::mpl;
  using boost::is_same;

  struct UDT {};
  struct incomplete;
  class abstract { public: virtual ~abstract() = 0; };

  template<typename s>
  struct empty_set_test
  {
    typedef equal_to< size<s>, int_<0> > t1;
    typedef empty<s> t2;

    typedef is_same< BOOST_DEDUCED_TYPENAME clear<s>::type, set0<> > t3;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,int>::type, void_ > t4;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,char>::type, void_ > t5;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,long>::type, void_ > t6;

    typedef not_< has_key<s,int> > t7;
    typedef not_< has_key<s,char> > t8;
    typedef not_< has_key<s,long> > t9;

    typedef is_same< BOOST_DEDUCED_TYPENAME order<s,int>::type, void_ > t10;
    typedef is_same< BOOST_DEDUCED_TYPENAME order<s,char>::type, void_ > t11;
    typedef is_same< BOOST_DEDUCED_TYPENAME order<s,long>::type, void_ > t12;

    typedef BOOST_DEDUCED_TYPENAME begin<s>::type first;
    typedef BOOST_DEDUCED_TYPENAME end<s>::type last;

    typedef is_same<first, last> t13;
    typedef equal_to< distance<first, last>, int_<0> > t14;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14>
      >::type type;
  };

  template<typename s>
  struct int_set_test
  {
    typedef equal_to< size<s>, int_<1> > t1;
    typedef not_< empty<s> > t2;

    typedef is_same< BOOST_DEDUCED_TYPENAME clear<s>::type, set0<> > t3;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,int>::type, int > t4;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,char>::type, void_ > t5;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,long>::type, void_ > t6;

    typedef has_key<s, int> t7;
    typedef not_< has_key<s,char> > t8;
    typedef not_< has_key<s,long> > t9;

    typedef not_< is_same< BOOST_DEDUCED_TYPENAME order<s,int>::type, void_ > > t10;
    typedef is_same< BOOST_DEDUCED_TYPENAME order<s,char>::type, void_ > t11;
    typedef is_same< BOOST_DEDUCED_TYPENAME order<s,long>::type, void_ > t12;

    typedef BOOST_DEDUCED_TYPENAME begin<s>::type first;
    typedef BOOST_DEDUCED_TYPENAME end<s>::type last;

    typedef is_same< BOOST_DEDUCED_TYPENAME deref<first>::type, int > t13;
    typedef is_same< BOOST_DEDUCED_TYPENAME next<first>::type, last > t14;

    typedef equal_to< distance<first, last>, int_<1> > t15;
    typedef contains<s, int> t16;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14, t15>
        , t16
      >::type type;
  };

  template<typename s>
  struct int_char_set_test
  {
    typedef equal_to< size<s>, int_<2> > t1;
    typedef not_< empty<s> > t2;
    typedef is_same< BOOST_DEDUCED_TYPENAME clear<s>::type, set0<> > t3;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s, int>::type, int > t4;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s, char>::type, char > t5;

    typedef has_key<s, char> t6;
    typedef not_< has_key<s, long> > t7;

    typedef not_<
          is_same <BOOST_DEDUCED_TYPENAME order<s,int>::type, void_>
      > t8;
    typedef not_<
          is_same <BOOST_DEDUCED_TYPENAME order<s,char>::type, void_>
      > t9;
    typedef is_same <BOOST_DEDUCED_TYPENAME order<s,long>::type, void_> t10;
    typedef not_<
          is_same <
              BOOST_DEDUCED_TYPENAME order<s,int>::type
            , BOOST_DEDUCED_TYPENAME order<s,char>::type
          >
      > t11;

    typedef BOOST_DEDUCED_TYPENAME begin<s>::type first;
    typedef BOOST_DEDUCED_TYPENAME end<s>::type last;

    typedef equal_to< distance<first, last>, int_<2> > t12;
    typedef contains<s,int> t13;
    typedef contains<s,char> t14;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14>
      >::type type;
  };

  template<typename s>
  struct int_char_long_set_test
  {
    typedef equal_to< size<s>, int_<3> > t1;
    typedef not_< empty<s> > t2;

    typedef is_same< BOOST_DEDUCED_TYPENAME clear<s>::type, set0<> > t3;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,int>::type, int > t4;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,char>::type, char > t5;
    typedef is_same< BOOST_DEDUCED_TYPENAME at<s,long>::type, long > t6;

    typedef has_key<s,long> t7;
    typedef has_key<s,int> t8;
    typedef has_key<s,char> t9;

    typedef BOOST_DEDUCED_TYPENAME order<s,int>::type o1;
    typedef BOOST_DEDUCED_TYPENAME order<s,char>::type o2;
    typedef BOOST_DEDUCED_TYPENAME order<s,long>::type o3;
    typedef not_< is_same<o1, void_> > t10;
    typedef not_< is_same<o2, void_> > t11;
    typedef not_< is_same<o3, void_> > t12;
    typedef not_< is_same<o1, o2> > t13;
    typedef not_< is_same<o1, o3> > t14;
    typedef not_< is_same<o2, o3> > t15;

    typedef BOOST_DEDUCED_TYPENAME begin<s>::type first;
    typedef BOOST_DEDUCED_TYPENAME end<s>::type last;
    typedef equal_to< distance<first, last>, int_<3> > t16;

    typedef contains<s, int> t17;
    typedef contains<s, char> t18;
    typedef contains<s, long> t19;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14, t15>
        , and_<t16, t17, t18, t19>
      >::type type;
  };

  template<typename S0, typename S1, typename S2, typename S3>
  struct basic_set_test
  {
    typedef empty_set_test<S0> t1;
    typedef empty_set_test<BOOST_DEDUCED_TYPENAME erase_key<S1,int>::type> t2;
    typedef empty_set_test<
          BOOST_DEDUCED_TYPENAME erase_key<
              BOOST_DEDUCED_TYPENAME erase_key<S2, char>::type
            , int
          >::type
      > t3;
    typedef empty_set_test<
          BOOST_DEDUCED_TYPENAME erase_key<
              BOOST_DEDUCED_TYPENAME erase_key<
                  BOOST_DEDUCED_TYPENAME erase_key<S3,char>::type
                  , long
              >::type
            , int
          >::type
      > t4;

    typedef int_set_test<S1> t5;
    typedef int_set_test< BOOST_DEDUCED_TYPENAME insert<S0,int>::type > t6;
    typedef int_set_test< BOOST_DEDUCED_TYPENAME erase_key<S2,char>::type > t7;
    typedef int_set_test<
          BOOST_DEDUCED_TYPENAME erase_key<
              BOOST_DEDUCED_TYPENAME erase_key<S3,char>::type
            , long
          >::type
      > t8;

    typedef int_char_set_test<S2> t9;
    typedef int_char_set_test<BOOST_DEDUCED_TYPENAME insert<S1,char>::type> t10;
    typedef
      int_char_set_test<BOOST_DEDUCED_TYPENAME erase_key<S3,long>::type> t11;
    typedef int_char_set_test<
          BOOST_DEDUCED_TYPENAME insert<
              BOOST_DEDUCED_TYPENAME insert<S0,char>::type
          , int
        >::type
      > t12;

    typedef int_char_long_set_test<S3> t13;
    typedef int_char_long_set_test<
          BOOST_DEDUCED_TYPENAME insert<
              BOOST_DEDUCED_TYPENAME insert<
                  BOOST_DEDUCED_TYPENAME insert<S0,char>::type
                , long
              >::type
            , int
          >::type
      > t14;
    typedef int_char_long_set_test<
          BOOST_DEDUCED_TYPENAME insert<
              BOOST_DEDUCED_TYPENAME insert<S1,long>::type
            , char
          >::type
      > t15;
    typedef int_char_long_set_test<
          BOOST_DEDUCED_TYPENAME insert<S2,long>::type
      > t16;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14, t15>
        , t16
      >::type type;
  };

  template<typename S1, typename S2>
  struct numbered_vs_variadic_set_test
  {
    typedef typename and_<
          is_same<S1, BOOST_DEDUCED_TYPENAME S1::type>
        , is_same<BOOST_DEDUCED_TYPENAME S2::type, S1>
      >::type type;
  };

  namespace testcase_1
  {
    typedef set0<> s01;
    typedef set<>  s02;
    typedef set1<int> s11;
    typedef set<int>  s12;
    typedef set2<int,char> s21;
    typedef set<int,char>  s22;
    typedef set<char,int>  s23;
    typedef set3<int,char,long> s31;
    typedef set<int,char,long>  s32;
    typedef set<int,long,char>  s33;
    typedef set<long,char,int>  s34;

    typedef numbered_vs_variadic_set_test<s01,s02> test_num_var_1;
    typedef numbered_vs_variadic_set_test<s11,s12> test_num_var_2;
    typedef numbered_vs_variadic_set_test<s21,s22> test_num_var_3;
    typedef numbered_vs_variadic_set_test<s31,s32> test_num_var_4;

    typedef basic_set_test<s01,s11,s21,s31> test_basic_1;
    typedef basic_set_test<s02,s12,s22,s32> test_basic_2;
    typedef basic_set_test<s01,s11,s23,s31> test_basic_3;
    typedef basic_set_test<s01,s11,s23,s33> test_basic_4;
    typedef basic_set_test<s01,s11,s23,s34> test_basic_5;

    MPLLIBS_ADD_TEST(suite, test_num_var_1)
    MPLLIBS_ADD_TEST(suite, test_num_var_2)
    MPLLIBS_ADD_TEST(suite, test_num_var_3)
    MPLLIBS_ADD_TEST(suite, test_num_var_4)
    MPLLIBS_ADD_TEST(suite, test_basic_1)
    MPLLIBS_ADD_TEST(suite, test_basic_2)
    MPLLIBS_ADD_TEST(suite, test_basic_3)
    MPLLIBS_ADD_TEST(suite, test_basic_4)
    MPLLIBS_ADD_TEST(suite, test_basic_5)
  }

  template<typename s>
  struct empty_set_types_variety_test
  {
    typedef not_< has_key<s,char> > t1;
    typedef not_< has_key<s,int> > t2;
    typedef not_< has_key<s,UDT> > t3;
    typedef not_< has_key<s,incomplete> > t4;

    typedef not_< has_key<s,char const> > t5;
    typedef not_< has_key<s,int const> > t6;
    typedef not_< has_key<s,UDT const> > t7;
    typedef not_< has_key<s,incomplete const> > t8;

    typedef not_< has_key<s,int*> > t9;
    typedef not_< has_key<s,UDT*> > t10;
    typedef not_< has_key<s,incomplete*> > t11;

    typedef not_< has_key<s,int&> > t12;
    typedef not_< has_key<s,UDT&> > t13;
    typedef not_< has_key<s,incomplete&> > t14;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14>
      >::type type;
  };

  template<typename s>
  struct set_types_variety_test
  {
    typedef equal_to< size<s>, int_<8> > t1;

    typedef has_key<s,char> t2;
    typedef has_key<s,int const> t3;
    typedef has_key<s,long*> t4;
    typedef has_key<s,UDT* const> t5;
    typedef has_key<s,incomplete> t6;
    typedef has_key<s,abstract> t7;
    typedef has_key<s,incomplete volatile&> t8;
    typedef has_key<s,abstract const&> t9;

    typedef not_< has_key<s,char const> > t10;
    typedef not_< has_key<s,int> > t11;
    typedef not_< has_key<s,long* const> > t12;
    typedef not_< has_key<s,UDT*> > t13;
    typedef not_< has_key<s,incomplete const> > t14;
    typedef not_< has_key<s,abstract volatile> > t15;
    typedef not_< has_key<s,incomplete&> > t16;
    typedef not_< has_key<s,abstract&> > t17;

    typedef typename and_<
          and_<t1, t2, t3, t4, t5>
        , and_<t6, t7, t8, t9, t10>
        , and_<t11, t12, t13, t14, t15>
        , and_<t16, t17>
      >::type type;
  };

  namespace testcase_2
  {
    typedef empty_set_types_variety_test< set<> > test_empty_types_1;
    typedef empty_set_types_variety_test< set<>::type > test_empty_types_2;

    typedef set<
          char, int const, long*, UDT* const, incomplete, abstract
        , incomplete volatile&, abstract const&
      > s;

    typedef set_types_variety_test<s> test_types_1;
    typedef set_types_variety_test<s::type> test_types_2;

    MPLLIBS_ADD_TEST(suite, test_empty_types_1)
    MPLLIBS_ADD_TEST(suite, test_empty_types_2)
    MPLLIBS_ADD_TEST(suite, test_types_1)
    MPLLIBS_ADD_TEST(suite, test_types_2)
  }

  template<typename s>
  struct find_test
  {
    typedef equal_to< size<s>, int_<3> > t1;

    typedef typename end<s>::type not_found;
    typedef
      not_< is_same<BOOST_DEDUCED_TYPENAME find<s,int>::type, not_found> > t2;
    typedef
      not_< is_same<BOOST_DEDUCED_TYPENAME find<s,long>::type, not_found> > t3;
    typedef
      not_< is_same<BOOST_DEDUCED_TYPENAME find<s,char>::type, not_found> > t4;
    typedef is_same<BOOST_DEDUCED_TYPENAME find<s,char*>::type, not_found> t5;

    typedef typename and_<t1, t2, t3, t4, t5>::type type;
  };

  namespace testcase_3
  {
    typedef set<int,long,char> s;

    typedef find_test<s> test_find_1;
    typedef find_test<s::type> test_find_2;

    MPLLIBS_ADD_TEST(suite, test_find_1)
    MPLLIBS_ADD_TEST(suite, test_find_2)
  }
}

