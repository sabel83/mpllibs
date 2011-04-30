// Copyright Endre Tamas SAJO (baja@inf.elte.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_2_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/test.h>

#include <boost/mpl/bind.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/type_traits/is_float.hpp>
#include <boost/type_traits/is_same.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite ("bind");

  using namespace boost::mpl;
  using boost::is_same;

  struct f1
  {
    template<typename T1> struct apply
    { typedef T1 type; };
  };

  struct f5
  {
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    struct apply
    { typedef T5 type; };
  };

  namespace testcase_1
  {
    typedef is_same<
          apply_wrap1< bind1<f1,_1>, int >::type
        , int
      > basic1;

    typedef is_same<
          apply_wrap5< bind1<f1,_5>, void,void,void,void,int >::type
        , int
      > basic2;

    typedef is_same<
          apply_wrap5<
              bind5<f5,_1,_2,_3,_4,_5>
            , void,void,void,void,int
          >::type
        , int
      > basic3;

    typedef is_same<
          apply_wrap5<
              bind5<f5,_5,_4,_3,_2,_1>
            , int,void,void,void,void
          >::type
        , int
      > basic4;

    MPLLIBS_ADD_TEST(suite, basic1)
    MPLLIBS_ADD_TEST(suite, basic2)
    MPLLIBS_ADD_TEST(suite, basic3)
    MPLLIBS_ADD_TEST(suite, basic4)
  }

  namespace testcase_2
  {
    typedef is_same<
          apply_wrap0< bind1<f1,int> >::type
        , int
      > full1;

    typedef is_same<
          apply_wrap0< bind5<f5,void,void,void,void,int> >::type
        , int
      > full2;

    MPLLIBS_ADD_TEST(suite, full1)
    MPLLIBS_ADD_TEST(suite, full2)
  }

  namespace testcase_3
  {
    typedef is_same<
          apply_wrap5<
              bind5< f5,_1,_2,_3,_4,bind1<f1,_1> >
            , int,void,void,void,void
          >::type
        , int
      > composition1;

    typedef is_same<
          apply_wrap5<
              bind5< f5,_1,_2,_3,_4,bind1<f1,_5> >
            , void,void,void,void,int
          >::type
        , int
      > composition2;

    MPLLIBS_ADD_TEST(suite, composition1)
    MPLLIBS_ADD_TEST(suite, composition2)
  }

//#if !defined(BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \0
//    && !defined(BOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS) \0
//    && BOOST_WORKAROUND(__MWERKS__, BOOST_TESTED_AT(0x3003))
  namespace testcase_4
  {
    typedef bind3< quote3<if_>, _1, bind1< quote1<next>, _2 >, _3 > f;

    typedef is_same<
          apply_wrap3<f, true_, int_<0>, int>::type
        , int_<1>
      > if1;

    typedef is_same<
          apply_wrap3<f, false_, int, int_<0> >::type
        , int_<0>
      > if2;

    MPLLIBS_ADD_TEST(suite, if1)
    MPLLIBS_ADD_TEST(suite, if2)
  }
//#endif
}

