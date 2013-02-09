#ifndef MPLLIBS_METAMONAD_UNBOX_HPP
#define MPLLIBS_METAMONAD_UNBOX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct box;

    namespace impl
    {
      template <class T>
      struct strict_unbox;

      template <class T>
      struct strict_unbox<box<T> > : returns<T> {};
    }

    MPLLIBS_LAZY_METAFUNCTION(unbox, (T)) ((impl::strict_unbox<T>));
  }
}

#endif

