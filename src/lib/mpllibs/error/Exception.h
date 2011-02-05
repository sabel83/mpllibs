#ifndef MPLLIBS_ERROR_EXCEPTION_H
#define MPLLIBS_ERROR_EXCEPTION_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/get_data.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace error
  {
    struct Exception_tag
    {
      typedef Exception_tag type;
    };
  
    template <class Data>
    struct Exception
    {
      typedef Exception_tag tag;
      typedef mpllibs::error::Exception<Data> type;
    };
    
    template <class>
    struct get_data_impl;
    
    template <>
    struct get_data_impl<mpllibs::error::Exception_tag>
    {
      template <class>
      struct apply;
      
      template <class Data>
      struct apply<mpllibs::error::Exception<Data> >
      {
        typedef Data type;
      };
    };
    
    
    /*
     * The Exception monad
     * This is modeled along the Either monad of Haskell
     *
     * A monadic value is either:
     *  - An Exception
     *  - A value wrapped with a class, that:
     *    - its tag is NoException_tag
     *    - its type is the wrapped value
     *
     */
    typedef Exception_tag ExceptionMonad;
    
    struct NoException_tag
    {
      typedef NoException_tag type;
    };
    
    template <class T>
    struct NoException
    {
      typedef mpllibs::error::NoException_tag tag;
      typedef T type;
    };
    
    
    /*
     * return
     */
    template <class>
    struct return__impl;
    
    template <>
    struct return__impl<mpllibs::error::Exception_tag>
    {
      template <class T>
      struct apply
      {
        typedef mpllibs::error::NoException<T> type;
      };
    };
    
    template <>
    struct return__impl<NoException_tag> :
      mpllibs::error::return__impl<mpllibs::error::Exception_tag>
    {};


    /*
     * bind
     */
    template <class>
    struct bind_impl;

    // Exception delegation
    template <>
    struct bind_impl<mpllibs::error::Exception_tag>
    {
      template <class a, class f>
      struct apply
      {
        typedef a type;
      };
    };
    
    // Normal evaluation
    template <>
    struct bind_impl<mpllibs::error::NoException_tag>
    {
      template <class a, class f>
      struct apply : boost::mpl::apply<f, typename a::type> {};
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <class a, class b>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::error::Exception_tag,
        mpllibs::error::Exception_tag
      >
    {
      template <class a, class b>
      struct apply :
        boost::mpl::equal_to<
          typename mpllibs::error::get_data<a>::type,
          typename mpllibs::error::get_data<b>::type
        >
      {};
    };
    
    template <>
    struct
      equal_to_impl<
        mpllibs::error::NoException_tag,
        mpllibs::error::NoException_tag
      >
    {
      template <class a, class b>
      struct apply : boost::mpl::equal_to<typename a::type, typename b::type>
      {};
    };
    
    template <>
    struct
      equal_to_impl<
        mpllibs::error::Exception_tag,
        mpllibs::error::NoException_tag
      >
    {
      template <class>
      struct apply : boost::mpl::false_ {};
    };
    
    template <>
    struct
      equal_to_impl<
        mpllibs::error::NoException_tag,
        mpllibs::error::Exception_tag
      >
    {
      template <class>
      struct apply : boost::mpl::false_ {};
    };
  }
}

#endif

