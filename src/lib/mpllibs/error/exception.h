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
#include <boost/mpl/if.hpp>

#include <boost/type_traits/is_same.hpp>

#include <iostream>

namespace mpllibs
{
  namespace error
  {
    struct exception_tag
    {
      typedef exception_tag type;
    };
  
    template <class Data>
    struct exception
    {
      typedef exception_tag tag;
      typedef exception type;
    };
    
    template <class>
    struct get_data_impl;
    
    template <>
    struct get_data_impl<mpllibs::error::exception_tag>
    {
      template <class>
      struct apply;
      
      template <class Data>
      struct apply<mpllibs::error::exception<Data> >
      {
        typedef Data type;
      };
    };
  }
  
  namespace metatest
  {
    template <class T>
    struct to_stream;
    
    template <class T>
    struct to_stream_impl;

    template <>
    struct to_stream_impl<mpllibs::error::exception_tag>
    {
      template <class E>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          using mpllibs::error::get_data;

          typedef typename get_data<E>::type Edata;
          return to_stream<Edata>::run(o_ << "Exception<") << ">";
        }
      };
    };
  }
  
  namespace error
  {
    /*
     * The Exception monad
     * This is modeled along the Either monad of Haskell
     *
     * A monadic value is either:
     *  - An exception
     *  - A value wrapped with a class, that:
     *    - its tag is no_exception_tag
     *    - its type is the wrapped value
     *
     */
    typedef exception_tag exception_monad;
    
    struct no_exception_tag
    {
      typedef no_exception_tag type;
    };
    
    template <class T>
    struct no_exception
    {
      typedef no_exception_tag tag;
      typedef T type;
    };
    
    
    /*
     * return
     */
    template <class>
    struct return__impl;
    
    template <>
    struct return__impl<exception_tag>
    {
      template <class T>
      struct apply
      {
        typedef no_exception<T> type;
      };
    };
    
    template <>
    struct return__impl<no_exception_tag> :
      mpllibs::error::return__impl<exception_tag>
    {};


    /*
     * bind
     */
    template <class>
    struct bind_impl;

    namespace impl
    {
      template <class Exception>
      struct propagate_exception
      {
        typedef Exception type;
      };
      
      template <class A, class F>
      struct eval_next_step : boost::mpl::apply<F, typename A::type> {};
    }

    template <>
    struct bind_impl<exception_tag>
    {
      template <class A, class F>
      struct apply :
        boost::mpl::if_<
          typename boost::is_same<
            exception_tag,
            typename boost::mpl::tag<A>::type
          >::type,
          mpllibs::error::impl::propagate_exception<A>,
          mpllibs::error::impl::eval_next_step<A, F>
        >::type
      {};
    };
    
    template <>
    struct bind_impl<no_exception_tag> : bind_impl<exception_tag> {};
  }
}

namespace boost
{
  namespace mpl
  {
    template <class A, class B>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::error::exception_tag,
        mpllibs::error::exception_tag
      >
    {
      template <class A, class B>
      struct apply :
        equal_to<
          typename mpllibs::error::get_data<A>::type,
          typename mpllibs::error::get_data<B>::type
        >
      {};
    };
    
    template <>
    struct
      equal_to_impl<
        mpllibs::error::no_exception_tag,
        mpllibs::error::no_exception_tag
      >
    {
      template <class A, class B>
      struct apply : equal_to<typename A::type, typename B::type>
      {};
    };
    
    template <>
    struct
      equal_to_impl<
        mpllibs::error::exception_tag,
        mpllibs::error::no_exception_tag
      >
    {
      template <class>
      struct apply : false_ {};
    };
    
    template <>
    struct
      equal_to_impl<
        mpllibs::error::no_exception_tag,
        mpllibs::error::exception_tag
      >
    {
      template <class>
      struct apply : false_ {};
    };
  }
}

#endif

