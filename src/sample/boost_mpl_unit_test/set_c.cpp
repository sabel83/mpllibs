// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/set_c.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/type_traits/is_same.hpp>

//
// turns out set_c iterators not working is in fact a bug in boost
// http://boost.2283326.n4.nabble.com/mpl-for-each-and-set-c-misunderstanding-or-bug-tt2565972.html
//

namespace
{
  const mpllibs::metatest::TestSuite suite ("set_c");

  using namespace boost;
  using namespace mpl;

  namespace test
  {
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    template< typename S, typename S::value_type k > 
    struct at_c
        : at< S, integral_c<typename S::value_type,k> >::type
    { };
#else
    template< typename S, long k > 
    struct at_c
        : aux::msvc_eti_base<
              at< S, integral_c<typename S::value_type,k> >
            >
    { };
#endif
  }

#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1200)
  namespace testcase_1
  {
    typedef set_c<bool,true>::type s1;
    typedef set_c<bool,false>::type s2;
    typedef set_c<bool,true,false>::type s3;

    typedef equal_to< size<s1>, int_<1> > test_size_1;
    typedef equal_to< size<s2>, int_<1> > test_size_2;
    typedef equal_to< size<s3>, int_<2> > test_size_3;

    typedef is_same<s1::value_type, bool> test_value_type_1;
    typedef is_same<s2::value_type, bool> test_value_type_2;
    typedef is_same<s3::value_type, bool> test_value_type_3;

#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    typedef equal_to< test::at_c<s1,true>, true_ > test_at_1;
    typedef equal_to< test::at_c<s2,false>, false_ > test_at_2;
    typedef equal_to< test::at_c<s3,true>, true_ > test_at_3;
    typedef equal_to< test::at_c<s3,false>, false_ > test_at_4;

    typedef is_same< test::at_c<s1,false>::type, void_ > test_at_5;
    typedef is_same< test::at_c<s2,true>::type, void_ > test_at_6;
#endif

    typedef begin<s1>::type first1;
    typedef end<s1>::type last1;
    typedef equal_to< distance<first1, last1>, int_<1> > test_iterator_1;

    typedef begin<s2>::type first2;
    typedef end<s2>::type last2;
    typedef equal_to< distance<first2, last2>, int_<1> > test_iterator_2;

    typedef begin<s3>::type first3;
    typedef end<s3>::type last3;
    typedef equal_to< distance<first3, last3>, int_<2> > test_iterator_3;

    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_size_3)
    MPLLIBS_ADD_TEST(suite, test_value_type_1)
    MPLLIBS_ADD_TEST(suite, test_value_type_2)
    MPLLIBS_ADD_TEST(suite, test_value_type_3)
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    MPLLIBS_ADD_TEST(suite, test_at_1)
    MPLLIBS_ADD_TEST(suite, test_at_2)
    MPLLIBS_ADD_TEST(suite, test_at_3)
    MPLLIBS_ADD_TEST(suite, test_at_4)
    MPLLIBS_ADD_TEST(suite, test_at_5)
    MPLLIBS_ADD_TEST(suite, test_at_6)
#endif
    //MPLLIBS_ADD_TEST(suite, test_iterator_1)
    //MPLLIBS_ADD_TEST(suite, test_iterator_2)
    //MPLLIBS_ADD_TEST(suite, test_iterator_3)
  }
#endif

  namespace testcase_2
  {
    typedef set_c<char, 'a'>::type s1;
    typedef set_c<char, 'a','b','c','d','e','f','g','h'>::type s2;

    typedef equal_to< size<s1>, int_<1> > test_size_1;
    typedef equal_to< size<s2>, int_<8> > test_size_2;

    typedef is_same<s1::value_type, char> test_value_type_1;
    typedef is_same<s2::value_type, char> test_value_type_2;

#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    typedef equal_to< test::at_c<s1,'a'>, int_<'a'> > test_at_1;
    typedef equal_to< test::at_c<s2,'a'>, int_<'a'> > test_at_2;
    typedef equal_to< test::at_c<s2,'d'>, int_<'d'> > test_at_3;
    typedef equal_to< test::at_c<s2,'h'>, int_<'h'> > test_at_4;

    typedef is_same< test::at_c<s1, 'z'>::type, void_ > test_at_5;
    typedef is_same< test::at_c<s2, 'k'>::type, void_ > test_at_6;
#endif

    typedef begin<s1>::type first1;
    typedef end<s1>::type last1;
    typedef equal_to< distance<first1, last1>, int_<1> > test_iterator_1;

    typedef begin<s2>::type first2;
    typedef end<s2>::type last2;
    typedef equal_to< distance<first2, last2>, int_<8> > test_iterator_2;

    MPLLIBS_ADD_TEST(suite, test_size_1)
    MPLLIBS_ADD_TEST(suite, test_size_2)
    MPLLIBS_ADD_TEST(suite, test_value_type_1)
    MPLLIBS_ADD_TEST(suite, test_value_type_2)
#if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
    MPLLIBS_ADD_TEST(suite, test_at_1)
    MPLLIBS_ADD_TEST(suite, test_at_2)
    MPLLIBS_ADD_TEST(suite, test_at_3)
    MPLLIBS_ADD_TEST(suite, test_at_4)
    MPLLIBS_ADD_TEST(suite, test_at_5)
    MPLLIBS_ADD_TEST(suite, test_at_6)
#endif
    //MPLLIBS_ADD_TEST(suite, test_iterator_1)
    //MPLLIBS_ADD_TEST(suite, test_iterator_2)
  }
}

