#ifndef MPLLIBS_METAMONAD_LAZY_PROTECT_ARGS_HPP
#define MPLLIBS_METAMONAD_LAZY_PROTECT_ARGS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(lazy_protect_args, (E)) ((E));

    template <class E>
    struct lazy;

    template <class E>
    struct lazy<lazy_protect_args<E> > : E {};
  }
}

#endif

