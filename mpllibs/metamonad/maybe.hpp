#ifndef MPLLIBS_METAMONAD_MAYBE_HPP
#define MPLLIBS_METAMONAD_MAYBE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/just.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>
#include <mpllibs/metamonad/nothing.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(maybe_tag)
    
    /*
     * return
     */
    template <class>
    struct return__impl;
    
    template <>
    struct return__impl<maybe_tag>
    {
      template <class T>
      struct apply : just<T> {};
    };


    /*
     * bind
     */
    template <class>
    struct bind_impl;

    template <>
    struct bind_impl<maybe_tag>
    {
    private:
      template <class A, class F>
      struct call_F : boost::mpl::apply<F, typename get_data<A>::type> {};
    public:
      template <class A, class F>
      struct apply :
        boost::mpl::if_<
          is_nothing<A>,
          boost::mpl::identity<A>,
          call_F<A, F>
        >::type
      {};
    };
  }
}

#endif

