// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#ifndef EITHER_MONAD_H
#define EITHER_MONAD_H

#include <mpllibs/error/return_.h>
#include <mpllibs/error/bind.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace
{
  /*
   * Either monad for testing
   */
  struct either_tag
  {
    typedef either_tag type;
  };
  
  struct left_tag
  {
    typedef left_tag type;
  };
  
  struct right_tag
  {
    typedef right_tag type;
  };

  typedef either_tag Either;
  
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
    template <>
    struct bind_impl<either_tag>
    {
      template <class a, class f>
      struct apply :
        boost::mpl::if_<
          typename boost::is_same<
            right_tag,
            typename boost::mpl::tag<a>::type
          >::type,
          boost::mpl::apply<f, a>,
          a
        >::type
      {};
    };
    
    template <>
    struct bind_impl<right_tag> : mpllibs::error::bind_impl<either_tag> {};
  
    template <>
    struct bind_impl<left_tag> : mpllibs::error::bind_impl<either_tag> {};
  }
}

#endif


