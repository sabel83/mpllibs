// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#ifndef EITHER_MONAD_H
#define EITHER_MONAD_H

#include <mpllibs/error/return_.h>
#include <mpllibs/error/bind.h>

#include <boost/mpl/equal_to.hpp>

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

#endif


