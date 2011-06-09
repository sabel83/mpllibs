#ifndef MPLLIBS_ERROR_RETURN__H
#define MPLLIBS_ERROR_RETURN__H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class>
    struct return__impl;
    // No default implementation
    
    struct no_return_argument;

    template <class MonadTag, class A = no_return_argument>
    struct return_ : boost::mpl::apply<return_<MonadTag>, A> {};
    
    template <class MonadTag>
    struct return_<MonadTag, no_return_argument>
    {
      template <class A>
      struct apply : boost::mpl::apply<return__impl<MonadTag>, A> {};
    };
  }
}

#endif

