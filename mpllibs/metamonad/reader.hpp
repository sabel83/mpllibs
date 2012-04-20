#ifndef MPLLIBS_METAMONAD_READER_HPP
#define MPLLIBS_METAMONAD_READER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(reader_tag)
    
    template <>
    struct monad<reader_tag> : monad_defaults<reader_tag>
    {
      struct return_
      {
        typedef return_ type;
        
        template <class T>
        struct apply
        {
          typedef boost::mpl::always<T> type;
        };
      };
      
      struct bind
      {
      private:
        template <class A, class F>
        struct impl
        {
          typedef impl type;
          
          template <class R>
          struct apply :
            boost::mpl::apply<
              typename boost::mpl::apply<
                F,
                typename boost::mpl::apply<A, R>::type
              >::type,
              R
            >
          {};
        };
      public:
        template <class A, class F>
        struct apply : impl<A, F> {};
        
        typedef bind type;
      };
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::reader_tag>::bind,
  "monad<reader_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::reader_tag>::return_,
  "monad<reader_tag>::return_"
)

#endif

