// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/int.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("apply");

  using namespace boost::mpl;
  using boost::is_same;

  template <typename T> struct std_vector
  {
#if defined(BOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS)
    typedef std_vector type;
    BOOST_MPL_AUX_LAMBDA_SUPPORT(1, std_vector, (T))
#endif
  };

  typedef plus<int_<2>, int_<3> > plus_2_3;
  typedef is_same<
        plus_2_3
      , lambda<plus_2_3>::type
    > test1;

  typedef is_same<
        std_vector<int>
      , lambda< std_vector<int> >::type
    > test2;

  typedef is_same<
        apply_wrap1<
            lambda< std_vector<_1> >::type
          , int>::type
      , std_vector<int>
    > test3;

  typedef equal_to<
        apply2< plus<_1, _2>, int_<2>, int_<3> >::type
      , int_<5>
    > test4;

  typedef is_same<
        apply1< _1, plus<_1, _2> >::type
      , plus<_1, _2>
    > test5;

  typedef equal_to<
        apply2<
            apply1< _1, plus<_1, _2> >::type
          , int_<2>
          , int_<3>
        >::type
      , int_<5>
    > test6;

  typedef is_same<
        apply_wrap1<
            lambda< lambda<_1> >::type
          , std_vector<int>
        >::type
      , std_vector<int>
    > test7;

  typedef is_same<
        apply_wrap1<
            apply_wrap1<
                lambda< lambda<_1> >::type
              , std_vector<_1>
            >::type
          , int
        >::type
      , std_vector<int>
    > test8;

  typedef is_same<
        apply1< _1, std_vector<int> >::type
      , std_vector<int>
    > test9;

  typedef is_same<
        apply1<
            apply1< _1, std_vector<_1> >::type
          , int
        >::type
      , std_vector<int>
    > test10;

  typedef is_same<
        apply1<
            lambda<_1>
          , std_vector<int>
        >::type
      , std_vector<int>
    > test11;

  typedef is_same<
        apply_wrap1<
            apply1<
                lambda<_1>
              , std_vector<_1>
            >::type
          , int
        >::type
      , std_vector<int>
    > test12;

  typedef equal_to<
        apply_wrap2<
            apply1<
                lambda<_1>
              , plus<_1, _2>
            >::type
          , int_<2>
          , int_<3>
        >::type
      , int_<5>
    > test13;

  typedef is_same<
        bind2<plus<>, _1, _1>
      , lambda< bind2<plus<>, _1, _1> >::type
    > test14;

#if !BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3003))
  typedef equal_to<
        apply_wrap1<
            lambda<
                lambda< bind2<plus<>, _1, _1> >
            >::type::type
          , int_<5>
        >::type
      , int_<10>
    > test15;
#endif

  typedef equal_to<
        apply1<
            bind2<plus<>, _1, _1>
          , int_<5>
        >::type
      , int_<10>
    > test16;

  typedef equal_to<
        apply_wrap2<
            apply1<
                _1, lambda< plus<_1, _2> >
            >::type::type
          , int_<2>
          , int_<3>
        >::type
      , int_<5>
    > test17;
}

MPLLIBS_ADD_TEST(suite, test1)
MPLLIBS_ADD_TEST(suite, test2)
MPLLIBS_ADD_TEST(suite, test3)
MPLLIBS_ADD_TEST(suite, test4)
MPLLIBS_ADD_TEST(suite, test5)
MPLLIBS_ADD_TEST(suite, test6)
MPLLIBS_ADD_TEST(suite, test7)
MPLLIBS_ADD_TEST(suite, test8)
MPLLIBS_ADD_TEST(suite, test9)
MPLLIBS_ADD_TEST(suite, test10)
MPLLIBS_ADD_TEST(suite, test11)
MPLLIBS_ADD_TEST(suite, test12)
MPLLIBS_ADD_TEST(suite, test13)
MPLLIBS_ADD_TEST(suite, test14)
#if !BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3003))
MPLLIBS_ADD_TEST(suite, test15)
#endif
MPLLIBS_ADD_TEST(suite, test16)
MPLLIBS_ADD_TEST(suite, test17)

