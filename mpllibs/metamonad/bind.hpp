#ifndef MPLLIBS_METAMONAD_BIND_HPP
#define MPLLIBS_METAMONAD_BIND_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class>
    struct bind_impl;
    // No default implementation
    
    // bind evaluates arguments lazily
    template <class MonadTag, class A, class F>
    struct bind : boost::mpl::apply<bind_impl<MonadTag>, A, F> {};
  }
}

#endif

