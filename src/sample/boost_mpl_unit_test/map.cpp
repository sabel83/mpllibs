
// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

// Updated to use metatest by Abel Sinkovics 2010.

#include <string>
#include <iostream>

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
#include <boost/mpl/pair.hpp>
#include <boost/mpl/equal_to.hpp>


#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

using namespace boost;
using namespace mpl;

// The tests use "UDT" and "incomplete", but this header
// defines a "main" function, so I need to include it into
// a namespace.
namespace boost_mpl_test
{
  #include <boost/mpl/aux_/test.hpp>
}

using boost_mpl_test::UDT;
using boost_mpl_test::incomplete;

namespace s1
{
    const mpllibs::metatest::test_suite suite("s1");

    typedef map2<
          mpl::pair<int,unsigned>
        , mpl::pair<char,unsigned char>
        > m_;

    typedef erase_key<m_,char>::type m;

    typedef bool_<size<m>::type::value == 1> t0;
    typedef not_<empty<m> > t1;
    typedef is_same< clear<m>::type,map0<> > t2;
    
    typedef is_same< at<m,int>::type,unsigned > t3;
    typedef is_same< at<m,char>::type,void_ > t4;
    typedef contains< m,mpl::pair<int,unsigned> > t5;
    typedef not_< contains< m,mpl::pair<int,int> > > t6;
    typedef not_< contains< m,mpl::pair<char,unsigned char> > > t7;

    typedef not_< has_key<m,char>::type > t8;
    typedef has_key<m,int>::type t9;
    
    typedef not_< is_same< order<m,int>::type, void_ > > t10;
    typedef is_same< order<m,char>::type,void_ > t11;

    typedef begin<m>::type first;
    typedef end<m>::type last;

    typedef is_same< deref<first>::type,mpl::pair<int,unsigned> > t12;
    typedef is_same< next<first>::type,last > t13;

    typedef insert<m,mpl::pair<char,long> >::type m2;

    typedef bool_< size<m2>::type::value == 2 > t14;
    typedef not_< empty<m2>::type > t15;
    typedef is_same< clear<m2>::type,map0<> > t16;
    typedef is_same< at<m2,int>::type,unsigned > t17;
    typedef is_same< at<m2,char>::type,long > t18;

    typedef contains< m2,mpl::pair<int,unsigned> > t19;
    typedef not_<  contains< m2,mpl::pair<int,int> > > t20;
    typedef not_<  contains< m2,mpl::pair<char,unsigned char> > > t21;
    typedef  contains< m2,mpl::pair<char,long> > t22;

    typedef  has_key<m2,char>::type t23;
    typedef not_<  has_key<m2,long>::type > t24;
    typedef not_<  is_same< order<m2,int>::type, void_ > > t25;
    typedef not_<  is_same< order<m2,char>::type, void_ > > t26;
    typedef not_<  is_same< order<m2,char>::type, order<m2,int>::type > > t27;

    typedef begin<m2>::type first2;
    typedef end<m2>::type last2;

    typedef  is_same<deref<first2>::type,mpl::pair<int,unsigned> > t28;
    typedef next<first2>::type iter;
    typedef  is_same<deref<iter>::type,mpl::pair<char,long> > t29;
    typedef  is_same< next<iter>::type,last2 > t30;

    typedef insert<m2,mpl::pair<int,unsigned> >::type s2_1;
    typedef  is_same<m2,s2_1> t31;

    typedef insert<m2,mpl::pair<long,unsigned> >::type m3;
    typedef boost::mpl::equal_to<boost::mpl::int_<3>, size<m3>::type> t32;
    typedef  has_key<m3,long>::type t33;
    typedef  has_key<m3,int>::type t34;
    typedef  has_key<m3,char>::type t35;
    typedef  contains< m3,mpl::pair<long,unsigned> > t36;
    typedef  contains< m3,mpl::pair<int,unsigned> > t37;

    typedef insert<m,mpl::pair<char,long> >::type m1;
    typedef boost::mpl::equal_to<boost::mpl::int_<2>, size<m1>::type> t38;
    typedef  is_same< at<m1,int>::type,unsigned > t39;
    typedef  is_same< at<m1,char>::type,long > t40;

    typedef  contains< m1,mpl::pair<int,unsigned> > t41;
    typedef not_< contains< m1,mpl::pair<int,int> > > t42;
    typedef not_< contains< m1,mpl::pair<char,unsigned char> > > t43;
    typedef  contains< m1,mpl::pair<char,long> > t44;

    typedef  is_same< m1,m2 > t45;

    typedef erase_key<m1,char>::type m_1;
    typedef  is_same<m,m_1> t46;
    typedef boost::mpl::equal_to<boost::mpl::int_<1>, size<m_1>::type> t47;
    typedef  is_same< at<m_1,char>::type,void_ > t48;
    typedef  is_same< at<m_1,int>::type,unsigned > t49;

    typedef erase_key<m3,char>::type m2_1;
    typedef boost::mpl::equal_to<boost::mpl::int_<2>, size<m2_1>::type> t50;
    typedef  is_same< at<m2_1,char>::type,void_ > t51;
    typedef  is_same< at<m2_1,int>::type,unsigned > t52;
    typedef  is_same< at<m2_1,long>::type,unsigned > t53;

    MPLLIBS_ADD_TEST(suite, t0)
    MPLLIBS_ADD_TEST(suite, t1)
    MPLLIBS_ADD_TEST(suite, t2)
    MPLLIBS_ADD_TEST(suite, t3)
    MPLLIBS_ADD_TEST(suite, t4)
    MPLLIBS_ADD_TEST(suite, t5)
    MPLLIBS_ADD_TEST(suite, t6)
    MPLLIBS_ADD_TEST(suite, t7)
    MPLLIBS_ADD_TEST(suite, t8)
    MPLLIBS_ADD_TEST(suite, t9)
    MPLLIBS_ADD_TEST(suite, t10)
    MPLLIBS_ADD_TEST(suite, t11)
    MPLLIBS_ADD_TEST(suite, t12)
    MPLLIBS_ADD_TEST(suite, t13)
    MPLLIBS_ADD_TEST(suite, t14)
    MPLLIBS_ADD_TEST(suite, t15)
    MPLLIBS_ADD_TEST(suite, t16)
    MPLLIBS_ADD_TEST(suite, t17)
    MPLLIBS_ADD_TEST(suite, t18)
    MPLLIBS_ADD_TEST(suite, t19)
    MPLLIBS_ADD_TEST(suite, t20)
    MPLLIBS_ADD_TEST(suite, t21)
    MPLLIBS_ADD_TEST(suite, t22)
    MPLLIBS_ADD_TEST(suite, t23)
    MPLLIBS_ADD_TEST(suite, t24)
    MPLLIBS_ADD_TEST(suite, t25)
    MPLLIBS_ADD_TEST(suite, t26)
    MPLLIBS_ADD_TEST(suite, t27)
    MPLLIBS_ADD_TEST(suite, t28)
    MPLLIBS_ADD_TEST(suite, t29)
    MPLLIBS_ADD_TEST(suite, t30)
    MPLLIBS_ADD_TEST(suite, t31)
    MPLLIBS_ADD_TEST(suite, t32)
    MPLLIBS_ADD_TEST(suite, t33)
    MPLLIBS_ADD_TEST(suite, t34)
    MPLLIBS_ADD_TEST(suite, t35)
    MPLLIBS_ADD_TEST(suite, t36)
    MPLLIBS_ADD_TEST(suite, t37)
    MPLLIBS_ADD_TEST(suite, t38)
    MPLLIBS_ADD_TEST(suite, t39)
    MPLLIBS_ADD_TEST(suite, t40)
    MPLLIBS_ADD_TEST(suite, t41)
    MPLLIBS_ADD_TEST(suite, t42)
    MPLLIBS_ADD_TEST(suite, t43)
    MPLLIBS_ADD_TEST(suite, t44)
    MPLLIBS_ADD_TEST(suite, t45)
    MPLLIBS_ADD_TEST(suite, t46)
    MPLLIBS_ADD_TEST(suite, t47)
    MPLLIBS_ADD_TEST(suite, t48)
    MPLLIBS_ADD_TEST(suite, t49)
    MPLLIBS_ADD_TEST(suite, t50)
    MPLLIBS_ADD_TEST(suite, t51)
    MPLLIBS_ADD_TEST(suite, t52)
    MPLLIBS_ADD_TEST(suite, t53)
}

namespace s2
{
    const mpllibs::metatest::test_suite suite("s2");

    typedef map0<> m;
    
    typedef bool_<size<m>::type::value == 0 > t0;
    typedef  empty<m>::type t1;

    typedef  is_same< clear<m>::type,map0<> > t2;
    typedef  is_same< at<m,char>::type,void_ > t3;

    typedef not_<  has_key<m,char>::type > t4;
    typedef not_<  has_key<m,int>::type > t5;
    typedef not_<  has_key<m,UDT>::type > t6;
    typedef not_<  has_key<m,incomplete>::type > t7;

    typedef not_<  has_key<m,char const>::type > t8;
    typedef not_<  has_key<m,int const>::type > t9;
    typedef not_<  has_key<m,UDT const>::type > t10;
    typedef not_<  has_key<m,incomplete const>::type > t11;

    typedef not_<  has_key<m,int*>::type > t12;
    typedef not_<  has_key<m,UDT*>::type > t13;
    typedef not_<  has_key<m,incomplete*>::type > t14;

    typedef not_<  has_key<m,int&>::type > t15;
    typedef not_<  has_key<m,UDT&>::type > t16;
    typedef not_<  has_key<m,incomplete&>::type > t17;

    typedef insert<m,mpl::pair<char,int> >::type m1;
    typedef bool_< size<m1>::type::value == 1 > t18;
    typedef  is_same< at<m1,char>::type,int > t19;

    typedef erase_key<m,char>::type m0_1;
    typedef bool_< size<m0_1>::type::value == 0 > t20;
    typedef  is_same< at<m0_1,char>::type,void_ > t21;

    MPLLIBS_ADD_TEST(suite, t0)
    MPLLIBS_ADD_TEST(suite, t1)
    MPLLIBS_ADD_TEST(suite, t2)
    MPLLIBS_ADD_TEST(suite, t3)
    MPLLIBS_ADD_TEST(suite, t4)
    MPLLIBS_ADD_TEST(suite, t5)
    MPLLIBS_ADD_TEST(suite, t6)
    MPLLIBS_ADD_TEST(suite, t7)
    MPLLIBS_ADD_TEST(suite, t8)
    MPLLIBS_ADD_TEST(suite, t9)
    MPLLIBS_ADD_TEST(suite, t10)
    MPLLIBS_ADD_TEST(suite, t11)
    MPLLIBS_ADD_TEST(suite, t12)
    MPLLIBS_ADD_TEST(suite, t13)
    MPLLIBS_ADD_TEST(suite, t14)
    MPLLIBS_ADD_TEST(suite, t15)
    MPLLIBS_ADD_TEST(suite, t16)
    MPLLIBS_ADD_TEST(suite, t17)
    MPLLIBS_ADD_TEST(suite, t18)
    MPLLIBS_ADD_TEST(suite, t19)
    MPLLIBS_ADD_TEST(suite, t20)
    MPLLIBS_ADD_TEST(suite, t21)
 }

namespace s3
{
    const mpllibs::metatest::test_suite suite("s3");

    typedef map< mpl::pair<int,int*> > map_of_1_pair;
    typedef begin<map_of_1_pair>::type iter_to_1_pair;
    
    typedef 
        is_same<
             deref<iter_to_1_pair>::type
           , mpl::pair<int,int*>
        >
     t0;
    
    typedef map<
        mpl::pair<int,int*>
      , mpl::pair<long,long*>
      , mpl::pair<char,char*>
    > mymap;
    
    typedef bool_< size<mymap>::value == 3 > t1;

    typedef end<mymap>::type not_found0;
    typedef not_<  is_same<find<mymap,mpl::pair<int,int*> >::type,not_found0> > t2;
    typedef not_<  is_same<find<mymap,mpl::pair<long,long*> >::type,not_found0> > t3;
    typedef not_<  is_same<find<mymap,mpl::pair<char,char*> >::type,not_found0> > t4;
    typedef  is_same<find<mymap,int>::type,not_found0> t5;


    typedef bool_< size<mymap::type>::value == 3 > t6;

    typedef end<mymap>::type not_found1;
    typedef not_<  is_same<find<mymap::type,mpl::pair<int,int*> >::type,not_found1> > t7;
    typedef not_<  is_same<find<mymap::type,mpl::pair<long,long*> >::type,not_found1> > t8;
    typedef not_<  is_same<find<mymap::type,mpl::pair<char,char*> >::type,not_found1> > t9;
    typedef  not_< is_same<find<mymap::type,int>::type,not_found1> > t10;

    MPLLIBS_ADD_TEST(suite, t0)
    MPLLIBS_ADD_TEST(suite, t1)
    MPLLIBS_ADD_TEST(suite, t2)
    MPLLIBS_ADD_TEST(suite, t3)
    MPLLIBS_ADD_TEST(suite, t4)
    MPLLIBS_ADD_TEST(suite, t5)
    MPLLIBS_ADD_TEST(suite, t6)
    MPLLIBS_ADD_TEST(suite, t7)
    MPLLIBS_ADD_TEST(suite, t8)
    MPLLIBS_ADD_TEST(suite, t9)
    MPLLIBS_ADD_TEST(suite, t10)
 }

namespace s4
{
    const mpllibs::metatest::test_suite suite("s4");

    typedef mpl::erase_key<
        mpl::map<
            mpl::pair<char, double>
          , mpl::pair<int, float>
        >
      , char
    >::type int_to_float_map;

    typedef mpl::insert<
        int_to_float_map
      , mpl::pair<char, long>
    >::type with_char_too;

    typedef 
        boost::is_same<
            mpl::at<with_char_too, char>::type
          , long
        >
    t0;

    MPLLIBS_ADD_TEST(suite, t0)
}

