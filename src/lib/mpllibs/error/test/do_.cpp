// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/do_.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

#include "common.h"

/*
 * WrapperMonad
 */
namespace
{
  struct wrapper_tag
  {
    typedef wrapper_tag type;
  };

  typedef wrapper_tag WrapperMonad;

  template <class t>
  struct Wrapped
  {
    typedef wrapper_tag tag;
    typedef t value;
    typedef Wrapped<t> type;
  };
}

namespace mpllibs
{
  namespace error
  {
    template <>
    struct return__impl<wrapper_tag>
    {
      template <class t>
      struct apply : Wrapped<t> {};
    };

    template <>
    struct bind_impl<wrapper_tag>
    {
      template <class a, class f>
      struct apply : boost::mpl::apply<f, a> {};
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<wrapper_tag, wrapper_tag>
    {
      template <class a, class b>
      struct apply : boost::mpl::equal_to<typename a::value, typename b::value>
      {};
    };
  }
}

namespace
{
  const mpllibs::metatest::TestSuite suite("do_");
  
  template <class a>
  struct minus_2 :
    Right<typename boost::mpl::minus<typename a::value, int2>::type>
  {};
  
  template <class t>
  struct eval_to_right : Right<typename t::type> {};

  typedef
    boost::mpl::equal_to<
      Right<int11>,
      DO<Either>::apply<
        SET<x, RETURN<int13> >,
        minus_2<x>
      >::type
    >
    TestDo;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      DO<Either>::apply<
        SET<x, RETURN<int13> >,
        SET<y, minus_2<x> >,
        minus_2<y>
      >::type
    >
    TestDoThreeSteps;

  typedef
    boost::mpl::equal_to<
      Right<int9>,
      DO<Either>::apply<
        SET<x, RETURN<int13> >,
        SET<y, minus_2<x> >,
        minus_2<x>,
        minus_2<y>
      >::type
    >
    TestDoTwoCalls;

  typedef
    boost::mpl::equal_to<
      Right<int13>,
      DO<Either>::apply<
        RETURN<int11>,
        RETURN<int13>
      >::type
    >
    TestDoTwoReturns;

  typedef
    boost::mpl::equal_to<
      Right<Right<int13> >,
      DO<Either>::apply<
        RETURN<
          DO<Either>::apply<
            RETURN<int13>
          >
        >
      >::type
    >
    TestNestedDoWithReturn;

  typedef
    boost::mpl::equal_to<
      Right<Right<int13> >,
      DO<Either>::apply<
        RETURN<RETURN<int13> >
      >::type
    >
    TestContentsOfReturnIsSubstituted;

  typedef
    boost::mpl::equal_to<
      Right<Wrapped<int13> >,
      DO<Either>::apply<
        eval_to_right<
          DO<WrapperMonad>::apply<
            RETURN<int13>
          >
        >
      >::type
    >
    TestNestedDoWithDifferentMonads;
}

MPLLIBS_ADD_TEST(suite, TestDo)
MPLLIBS_ADD_TEST(suite, TestDoThreeSteps)
MPLLIBS_ADD_TEST(suite, TestDoTwoCalls)
MPLLIBS_ADD_TEST(suite, TestDoTwoReturns)
MPLLIBS_ADD_TEST(suite, TestNestedDoWithReturn)
MPLLIBS_ADD_TEST(suite, TestContentsOfReturnIsSubstituted)
MPLLIBS_ADD_TEST(suite, TestNestedDoWithDifferentMonads)





