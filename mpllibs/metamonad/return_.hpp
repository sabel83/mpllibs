#ifndef MPLLIBS_METAMONAD_RETURN__HPP
#define MPLLIBS_METAMONAD_RETURN__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
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
    struct return_ : boost::mpl::apply_wrap1<return_<MonadTag>, A> {};
    
    template <class MonadTag>
    struct return_<MonadTag, no_return_argument>
    {
      template <class A>
      struct apply : boost::mpl::apply_wrap1<return__impl<MonadTag>, A> {};
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE_WITH_DEFAULTS(
  1,
  2,
  mpllibs::metamonad::return_,
  "return_"
);

#endif

