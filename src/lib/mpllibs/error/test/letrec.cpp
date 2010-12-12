// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/letrec.h>
#include <mpllibs/error/lambda.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("letrec");

  struct x;
  struct y;
  
  typedef boost::mpl::int_<0> int0;
  typedef boost::mpl::int_<1> int1;
  typedef boost::mpl::int_<2> int2;
  typedef boost::mpl::int_<4> int4;
  typedef boost::mpl::int_<11> int11;
  typedef boost::mpl::int_<13> int13;
  typedef boost::mpl::int_<24> int24;
  typedef boost::mpl::int_<26> int26;
  typedef boost::mpl::int_<37> int37;
  
  template <class T>
  struct lazy_double_value : boost::mpl::times<typename T::type, int2> {};
  
  template <class a, class b>
  struct lazy_plus :
    boost::mpl::plus<typename a::type, typename b::type>
  {};

  template <class a, class b>
  struct double_lazy_plus :
    boost::mpl::plus<typename a::type::type, typename b::type::type>
  {};

  template <class a, class b>
  struct lazy_times : boost::mpl::times<typename a::type, typename b::type> {};

  template <class c, class t, class f>
  struct lazy_eval_if : boost::mpl::eval_if<typename c::type, t, f> {};

  template <class a, class b>
  struct lazy_equal_to :
    boost::mpl::equal_to<typename a::type, typename b::type>
  {};

  template <class f, class a1>
  struct lazy_apply : boost::mpl::apply<typename f::type, a1> {};

  typedef
    boost::mpl::equal_to<
      int13,
      // name is replaced with a nullary metafunction evaluating to the
      // substituted expression
      mpllibs::error::letrec<x, int13, x>::type::type
    >
    TestLetrecName;

  typedef
    boost::mpl::equal_to<int11, mpllibs::error::letrec<x, int13, int11>::type>
    TestLetrecNotName;
  
  typedef
    boost::mpl::equal_to<
      int26,
      mpllibs::error::letrec<x, int13, lazy_double_value<x> >::type
    >
    TestTemplate;

  typedef
    boost::mpl::equal_to<
      int24,
      mpllibs::error::letrec<
        x, int13,
        mpllibs::error::letrec<y, int11, lazy_plus<x, y> >::type
      >::type::type
    >
    TestNestedLetrec;
  
  typedef
    boost::mpl::equal_to<
      int37,
      mpllibs::error::letrec<
        x, int13,
        double_lazy_plus<
          x,
          mpllibs::error::letrec<x, int11, lazy_plus<x, int13> >
        >
      >::type::type
    >
    TestShadowing;
  
  typedef
    boost::mpl::equal_to<
      int24,
      mpllibs::error::letrec<
        x,
        mpllibs::error::lambda<
          y,
          lazy_eval_if<
            lazy_equal_to<y, int0>,
            int1,
            lazy_times<lazy_apply<x, boost::mpl::minus<y, int1> >, y>
          >
        >,
        lazy_apply<x, int4>
      >::type::type
    >
    TestRecursion;
}

MPLLIBS_ADD_TEST(suite, TestLetrecName)
MPLLIBS_ADD_TEST(suite, TestLetrecNotName)
MPLLIBS_ADD_TEST(suite, TestTemplate)
MPLLIBS_ADD_TEST(suite, TestNestedLetrec)
MPLLIBS_ADD_TEST(suite, TestShadowing)
MPLLIBS_ADD_TEST(suite, TestRecursion)




