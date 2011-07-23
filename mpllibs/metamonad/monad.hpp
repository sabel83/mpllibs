#ifndef MPLLIBS_METAMONAD_MONAD_HPP
#define MPLLIBS_METAMONAD_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/typeclass.hpp>
#include <mpllibs/metamonad/throw.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/always.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    template <class Tag>
    struct monad
    {
      MPLLIBS_TYPECLASS_EXPECT(return_)
      MPLLIBS_TYPECLASS_EXPECT(bind)
      MPLLIBS_TYPECLASS_EXPECT(bind_)
    };
    
    template <class Tag>
    struct monad_defaults : monad<typeclass_expectations>
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

      struct fail
      {
        typedef fail type;
      
        template <class S>
        struct apply : MPLLIBS_THROW<S> {};
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            o_ << "monad<";
            mpllibs::metatest::to_stream<Tag>::run(o_);
            return o_ << ">::fail";
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

