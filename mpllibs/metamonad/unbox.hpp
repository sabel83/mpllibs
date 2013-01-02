#ifndef MPLLIBS_METAMONAD_UNBOX_HPP
#define MPLLIBS_METAMONAD_UNBOX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct unbox;

    template <class T>
    struct box;

    template <class T>
    struct unbox<box<T> > : returns<T> {};
  }
}

#endif

