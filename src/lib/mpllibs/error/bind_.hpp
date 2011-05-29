#ifndef MPLLIBS_ERROR_BIND__H
#define MPLLIBS_ERROR_BIND__H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/bind.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class MonadTag>
    struct bind__impl
    {
      template <class A, class B>
      struct apply :
        boost::mpl::apply<
          mpllibs::error::bind_impl<MonadTag>,
          A,
          boost::mpl::always<B>
        >
      {};
    };

    // bind_ evaluates its arguments lazily
    template <class MonadTag, class A, class B>
    struct bind_ :
      boost::mpl::apply<
        mpllibs::error::bind__impl<typename MonadTag::type>,
        typename A::type,
        typename B::type
      >
    {};
  }
}

#endif

