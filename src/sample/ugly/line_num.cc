// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/vector.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/equal.hpp>

#include <boost/mpl/aux_/test.hpp>

// MPL_TEST_CASE and various asserts use preprocessor line number information
// to guarantee unique names

#line 1
MPL_TEST_CASE()
{
  using namespace boost::mpl;
  typedef vector2<char,short> v2;

#line 1
  MPL_ASSERT(( equal<v2, v2::type > ));

#line 1
  MPL_ASSERT(( equal<v2, v2::type > ));
}

#line 1
MPL_TEST_CASE()
{
  using namespace boost::mpl;
  typedef vector3<char,short,int> v3;
  MPL_ASSERT(( equal<v3, v3::type > ));
}

// $ g++ -c line_num.cpp
// line_num.cpp: In function ‘void test1()’:
// line_num.cpp:1: error: conflicting declaration ‘mpl_assertion_in_line_1’
// line_num.cpp:1: error: ‘mpl_assertion_in_line_1’ has a previous declaration as
// ‘test1()::<anonymous enum> mpl_assertion_in_line_1’
// line_num.cpp: In function ‘void test1()’:
// line_num.cpp:1: error: redefinition of ‘void test1()’
// line_num.cpp:1: error: ‘void test1()’ previously defined here

