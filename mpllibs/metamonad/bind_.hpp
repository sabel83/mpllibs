#ifndef MPLLIBS_METAMONAD_BIND__HPP
#define MPLLIBS_METAMONAD_BIND__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/bind.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class MonadTag>
    struct bind__impl
    {
      template <class A, class B>
      struct apply :
        boost::mpl::apply_wrap2<bind_impl<MonadTag>, A, boost::mpl::always<B> >
      {};
    };

    // bind_ evaluates its arguments lazily
    template <class MonadTag, class A, class B>
    struct bind_ :
      boost::mpl::apply_wrap2<bind__impl<MonadTag>, A, B>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "bind_<";
          mpllibs::metatest::to_stream_argument_list<MonadTag, A, B>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

