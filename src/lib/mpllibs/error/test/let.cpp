// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/let.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/plus.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("let");

  struct x;
  struct y;
  
  typedef boost::mpl::int_<2> int2;
  typedef boost::mpl::int_<11> int11;
  typedef boost::mpl::int_<13> int13;
  typedef boost::mpl::int_<24> int24;
  typedef boost::mpl::int_<26> int26;
  typedef boost::mpl::int_<37> int37;
  
  template <class T>
  struct double_value : boost::mpl::times<T, int2> {};
  
  template <class a, class b>
  struct double_lazy_plus :
    boost::mpl::plus<typename a::type::type, typename b::type::type>
  {};

  typedef
    boost::mpl::equal_to<int13, mpllibs::error::let<x, int13, x>::type>
    TestLetName;

  typedef
    boost::mpl::equal_to<int11, mpllibs::error::let<x, int13, int11>::type>
    TestLetNotName;
  
  typedef
    boost::mpl::equal_to<
      int26,
      mpllibs::error::let<x, int13, double_value<x> >::type
    >
    TestTemplate;

  typedef
    boost::mpl::equal_to<
      int24,
      mpllibs::error::let<
        x, int13,
        mpllibs::error::let<y, int11, boost::mpl::plus<x, y> >::type
      >::type::type
    >
    TestNestedLet;
  
  typedef
    boost::mpl::equal_to<
      int37,
      mpllibs::error::let<
        x, int13,
        double_lazy_plus<
          x,
          mpllibs::error::let<x, int11, boost::mpl::plus<x, int13> >
        >
      >::type::type
    >
    TestShadowing;
}

MPLLIBS_ADD_TEST(suite, TestLetName)
MPLLIBS_ADD_TEST(suite, TestLetNotName)
MPLLIBS_ADD_TEST(suite, TestTemplate)
MPLLIBS_ADD_TEST(suite, TestNestedLet)
MPLLIBS_ADD_TEST(suite, TestShadowing)




