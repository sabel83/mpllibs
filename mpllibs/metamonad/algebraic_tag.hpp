#ifndef MPLLIBS_METAMONAD_ALGEBRAIC_TAG_HPP
#define MPLLIBS_METAMONAD_ALGEBRAIC_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_LAZY_METAFUNCTION(algebraic_tag, (T))
    ((returns<typename T::algebraic_tag>));
  }
}

#endif

