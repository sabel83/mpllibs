#ifndef MPLLIBS_METAMONAD_V1_LAZY_PROTECT_ARGS_HPP
#define MPLLIBS_METAMONAD_V1_LAZY_PROTECT_ARGS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/lazy_protect_args.hpp>
#include <mpllibs/metamonad/v1/fwd/lazy.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(lazy_protect_args, (E)) ((E));

      template <class E>
      struct lazy<lazy_protect_args<E> > : E {};
    }
  }
}

#endif

