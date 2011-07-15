#ifndef MPLLIBS_METAMONAD_EITHER_HPP
#define MPLLIBS_METAMONAD_EITHER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/left.hpp>
#include <mpllibs/metamonad/right.hpp>
#include <mpllibs/metamonad/is_left.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(either_tag)
    
    /*
     * return
     */
    template <class>
    struct return__impl;
    
    template <>
    struct return__impl<either_tag>
    {
      template <class T>
      struct apply : right<T> {};
    };


    /*
     * bind
     */
    template <class>
    struct bind_impl;

    template <>
    struct bind_impl<either_tag>
    {
    private:
      template <class A, class F>
      struct call_F : boost::mpl::apply<F, typename get_data<A>::type> {};
    public:
      template <class A, class F>
      struct apply :
        boost::mpl::if_<
          is_left<A>,
          boost::mpl::identity<A>,
          call_F<A, F>
        >::type
      {};
    };
  }
}

#endif

