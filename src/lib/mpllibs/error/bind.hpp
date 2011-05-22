#ifndef MPLLIBS_ERROR_BIND_H
#define MPLLIBS_ERROR_BIND_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class>
    struct bind_impl;
    // No default implementation
    
    // bind evaluates arguments lazily
    template <class MonadTag, class A, class F>
    struct bind :
      boost::mpl::apply<
        mpllibs::error::bind_impl<typename MonadTag::type>,
        typename A::type,
        typename F::type
      >
    {};
  }
}

#endif

