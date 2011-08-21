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
    struct writer_tag
    {
      typedef writer_tag type;
      struct to_stream
      {
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "writer_tag<";
          mpllibs::metatest::to_stream<M>::run(o_);
          return o_ << ">";
        }
      };
    };
    
    template <class M>
    struct monad<writer_tag<M> > : monad_defaults<writer_tag<M> >
    {
      struct return_
      {
        typedef return_ type;
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            o_ << "monad<";
            mpllibs::metatest::to_stream<writer_tag<M> >::run(o_);
            return o_ << ">::return_";
          }
        };
        
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

        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            o_ << "monad<";
            mpllibs::metatest::to_stream<writer_tag<M> >::run(o_);
            return o_ << ">::bind";
          }
        };
      };
    };
  }
}

#endif

