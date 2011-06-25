#ifndef MPLLIBS_METAMONAD_BIND__HPP
#define MPLLIBS_METAMONAD_BIND__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/bind.hpp>

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
    struct bind_ : boost::mpl::apply_wrap2<bind__impl<MonadTag>, A, B> {};
  }
}

#endif

