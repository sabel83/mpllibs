#ifndef MPLLIBS_METAMONAD_MONAD_HPP
#define MPLLIBS_METAMONAD_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/always.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    template <class T>
    struct to_stream;
  }
  
  namespace metamonad
  {
    template <class Tag>
    struct monad;
    
    template <class Tag>
    struct monad_defaults
    {
      struct bind_
      {
        typedef bind_ type;
      
        template <class A, class B>
        struct apply :
          boost::mpl::apply_wrap2<
            typename monad<Tag>::bind,
            A,
            boost::mpl::always<B>
          >
        {};
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            o_ << "monad<";
            mpllibs::metatest::to_stream<Tag>::run(o_);
            return o_ << ">::bind_";
          }
        };
      };
    };
  }
  
  namespace metatest
  {
    template <class Tag>
    struct to_stream<mpllibs::metamonad::monad<Tag> >
    {
      static std::ostream& run(std::ostream& o_)
      {
        o_ << "monad<";
        mpllibs::metatest::to_stream<Tag>::run(o_);
        return o_ << ">";
      }
    };
  }
}

#endif

