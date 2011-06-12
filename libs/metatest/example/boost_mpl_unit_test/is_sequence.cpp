// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/range_c.hpp>

namespace
{
  const mpllibs::metatest::suite_path suite ("is_sequence");

  using namespace boost::mpl;

  template<typename T> struct std_vector
  {
    T* begin();
  };

  struct UDT {};

  typedef is_sequence< std_vector<int> > test1;
  typedef is_sequence< int_<0> > test2;
  typedef is_sequence< int > test3;
  typedef is_sequence< int& > test4;
  typedef is_sequence< UDT > test5;
  typedef is_sequence< UDT* > test6;
  typedef is_sequence< range_c<int,0,0> > test7;
  typedef is_sequence< list<> > test8;
  typedef is_sequence< list<int> > test9;
  typedef is_sequence< vector<> > test10;
  typedef is_sequence< vector<int> > test11;
}

MPLLIBS_ADD_TEST_TO_FAIL(suite, test1)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test2)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test3)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test4)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test5)
MPLLIBS_ADD_TEST_TO_FAIL(suite, test6)
MPLLIBS_ADD_TEST(suite, test7)
MPLLIBS_ADD_TEST(suite, test8)
MPLLIBS_ADD_TEST(suite, test9)
MPLLIBS_ADD_TEST(suite, test10)
MPLLIBS_ADD_TEST(suite, test11)

