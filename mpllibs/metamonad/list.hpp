#ifndef MPLLIBS_METAMONAD_LIST_HPP
#define MPLLIBS_METAMONAD_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/transform.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(list_tag)
    
    /*
     * return
     */
    template <class>
    struct return__impl;
    
    template <>
    struct return__impl<list_tag>
    {
      template <class T>
      struct apply : boost::mpl::list<T> {};
    };


    /*
     * bind
     */
    template <class>
    struct bind_impl;
    
    namespace impl
    {
      struct join_lists
      {
        template <class State, class NewList>
        struct apply :
          boost::mpl::insert_range<
            State,
            typename boost::mpl::end<State>::type,
            NewList
          >
        {};
      };
    }

    template <>
    struct bind_impl<list_tag>
    {
      template <class A, class F>
      struct apply :
        boost::mpl::fold<
          typename boost::mpl::transform<A, F>::type,
          boost::mpl::list<>,
          mpllibs::metamonad::impl::join_lists
        >
      {};
    };
  }
}

#endif

