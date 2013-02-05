#ifndef MPLLIBS_METAMONAD_ALREADY_LAZY_HPP
#define MPLLIBS_METAMONAD_ALREADY_LAZY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(already_lazy, (AnglyExpr)) ((AnglyExpr));

    template <class AnglyExpr>
    struct lazy;

    template <class AnglyExpr>
    struct lazy<already_lazy<AnglyExpr> > : returns<AnglyExpr> {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::already_lazy,
  "already_lazy"
)

#endif

