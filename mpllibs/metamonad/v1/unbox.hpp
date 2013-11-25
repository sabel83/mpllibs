#ifndef MPLLIBS_METAMONAD_V1_UNBOX_HPP
#define MPLLIBS_METAMONAD_V1_UNBOX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/unbox.hpp>
#include <mpllibs/metamonad/v1/impl/strict_unbox.hpp>
#include <mpllibs/metamonad/v1/lazy_metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_LAZY_METAFUNCTION(unbox, (T)) ((impl::strict_unbox<T>));
    }
  }
}

#endif

