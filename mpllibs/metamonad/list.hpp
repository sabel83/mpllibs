#ifndef MPLLIBS_METAMONAD_LIST_HPP
#define MPLLIBS_METAMONAD_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/monad.hpp>

#include <boost/mpl/insert_range.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/transform.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(list_tag)
    
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
    struct monad<list_tag> : monad_defaults<list_tag>
    {
      struct return_
      {
        typedef return_ type;
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            return o_ << "monad<list_tag>::return_";
          }
        };

        template <class T>
        struct apply : boost::mpl::list<T> {};
      };
      
      struct bind
      {
        typedef bind type;
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            return o_ << "monad<list_tag>::bind";
          }
        };

        template <class A, class F>
        struct apply :
          boost::mpl::fold<
            typename boost::mpl::transform<A, F>::type,
            boost::mpl::list<>,
            mpllibs::metamonad::impl::join_lists
          >
        {};
      };
    };
  }
}

#endif

