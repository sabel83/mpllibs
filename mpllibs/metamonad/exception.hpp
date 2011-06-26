#ifndef MPLLIBS_METAMONAD_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>

#include <boost/type_traits/is_same.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(exception_tag);
  
    template <class Data>
    struct exception
    {
      typedef exception_tag tag;
      typedef exception type;

      typedef Data data;
    };
    
    template <class>
    struct get_data_impl;
    
    template <>
    struct get_data_impl<exception_tag>
    {
      template <class E>
      struct apply
      {
        typedef typename E::data type;
      };
    };
  }
  
  namespace metatest
  {
    template <>
    struct to_stream_impl<mpllibs::metamonad::exception_tag>
    {
      template <class E>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          using mpllibs::metamonad::get_data;

          typedef typename get_data<E>::type edata;
          return to_stream<edata>::run(o_ << "exception<") << ">";
        }
      };
    };
  }
  
  namespace metamonad
  {
    /*
     * The Exception monad
     * This is modeled along the Either monad of Haskell
     *
     * A monadic value is either:
     *  - An exception
     *  - Any other value
     *
     */
    typedef exception_tag exception_monad;
    
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
        typedef T type;
      };
    };


    /*
     * bind
     */
    template <class>
    struct bind_impl;

    template <>
    struct bind_impl<exception_tag>
    {
      template <class A, class F>
      struct apply :
        boost::mpl::if_<
          boost::is_same<exception_tag, typename boost::mpl::tag<A>::type>,
          boost::mpl::identity<A>,
          boost::mpl::apply<F, A>
        >::type
      {};
    };
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
        mpllibs::metamonad::exception_tag,
        mpllibs::metamonad::exception_tag
      >
    {
      template <class A, class B>
      struct apply :
        equal_to<
          typename mpllibs::metamonad::get_data<A>::type,
          typename mpllibs::metamonad::get_data<B>::type
        >
      {};
    };

    template <class T>
    struct equal_to_impl<mpllibs::metamonad::exception_tag, T>
    {
      template <class A, class B>
      struct apply : boost::mpl::false_ {};
    };

    template <class T>
    struct equal_to_impl<T, mpllibs::metamonad::exception_tag> :
      equal_to_impl<mpllibs::metamonad::exception_tag, T>
    {};
  }
}

#endif

