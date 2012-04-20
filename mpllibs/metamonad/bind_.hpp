#ifndef MPLLIBS_METAMONAD_BIND__HPP
#define MPLLIBS_METAMONAD_BIND__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/monad.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class MonadTag, class A, class B>
    struct bind_ :
      boost::mpl::apply_wrap2<
        typename mpllibs::metamonad::monad<MonadTag>::bind_,
        A,
        B
      >
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  3,
  mpllibs::metamonad::bind_,
  "bind_"
)

#endif

