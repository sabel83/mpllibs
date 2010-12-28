// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/return_.h>
#include <mpllibs/error/bind.h>

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/minus.hpp>

#include <boost/static_assert.hpp>

#include "common.h"

namespace
{
  /*
   * Either monad for testing
   */
  struct either_tag;
  struct left_tag;
  struct right_tag;

  struct Either
  {
    typedef either_tag tag;
  };
  
  template <class t>
  struct Left
  {
    typedef left_tag tag;
    typedef t value;
    typedef Left<t> type;
  };
  
  template <class t>
  struct Right
  {
    typedef right_tag tag;
    typedef t value;
    typedef Right<t> type;
  };
}

namespace mpllibs
{
  namespace error
  {
    template <>
    struct return__impl<either_tag>
    {
      template <class t>
      struct apply : Right<t> {};
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <>
    struct equal_to_impl<left_tag, left_tag>
    {
      template <class a, class b>
      struct apply :
        boost::mpl::equal_to<typename a::value, typename b::value>
      {};
    };

    template <>
    struct equal_to_impl<right_tag, right_tag> :
      equal_to_impl<left_tag, left_tag>
    {};

    template <>
    struct equal_to_impl<right_tag, left_tag>
    {
      template <class a, class b>
      struct apply : boost::mpl::identity<boost::mpl::false_>
      {};
    };
    
    template <>
    struct equal_to_impl<left_tag, right_tag> :
      equal_to_impl<right_tag, left_tag>
    {};
  }
}

namespace mpllibs
{
  namespace error
  {
    template <class t>
    struct bind_impl<right_tag, t>
    {
      template <class a, class f>
      struct apply : boost::mpl::apply<f, a> {};
    };

    template <class t>
    struct bind_impl<left_tag, t>
    {
      template <class a, class f>
      struct apply : a {};
    };
  }
}

namespace
{
  struct minus_2
  {
    typedef minus_2 type;
  
    template <class a>
    struct apply :
      Right<typename boost::mpl::minus<typename a::value, int2>::type>
    {};
  };
}

namespace
{
  const mpllibs::metatest::TestSuite suite("monad");
  
  typedef
    boost::mpl::equal_to<
      Right<int13>,
      boost::mpl::apply<mpllibs::error::return_<Either>, int13>::type
    >
    TestReturn;

  typedef
    boost::mpl::equal_to<
      Right<int11>,
      mpllibs::error::bind<Right<int13>, minus_2>::type
    >
    TestBindRight;

  typedef
    boost::mpl::equal_to<
      Left<int13>,
      mpllibs::error::bind<Left<int13>, minus_2>::type
    >
    TestBindLeft;
}

MPLLIBS_ADD_TEST(suite, TestReturn)
MPLLIBS_ADD_TEST(suite, TestBindLeft)
MPLLIBS_ADD_TEST(suite, TestBindRight)



