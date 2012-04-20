#ifndef MPLLIBS_METAMONAD_WRITER_HPP
#define MPLLIBS_METAMONAD_WRITER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/pair.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class M>
    struct writer_tag {};
    
    template <class M>
    struct monad<writer_tag<M> > : monad_defaults<writer_tag<M> >
    {
      struct return_
      {
        typedef return_ type;
        
        template <class T>
        struct apply
        {
          typedef boost::mpl::pair<T, typename monoid<M>::empty> type;
        };
      };
      
      struct bind
      {
        template <class A, class F>
        struct apply
        {
        private:
          typedef
            typename boost::mpl::apply<F, typename A::first>::type
            FA_first;
        public:
          typedef
            boost::mpl::pair<
              typename FA_first::first,
              typename boost::mpl::apply<
                typename monoid<M>::append,
                typename A::second,
                typename FA_first::second
              >::type
            >
            type;
        };
        
        typedef bind type;
      };
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::writer_tag,
  "writer_tag"
)

#endif

