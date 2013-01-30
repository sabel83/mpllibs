#ifndef MPLLIBS_METAMONAD_TRY_HPP
#define MPLLIBS_METAMONAD_TRY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/try_c.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class F>
    struct try_;

    template <class F>
    struct try_<syntax<F> > : try_c<F> {};
  }
}

#endif

