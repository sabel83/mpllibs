#ifndef MPLLIBS_METAMONAD_LAZY_ARGUMENT_HPP
#define MPLLIBS_METAMONAD_LAZY_ARGUMENT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    // Not defined. Using it outside of lazy is an error.
    template <class AnglyExpr>
    struct lazy_argument;

    template <class AnglyExpr>
    struct lazy;

    template <class AnglyExpr>
    struct lazy<lazy_argument<AnglyExpr> > : returns<lazy<AnglyExpr> > {};

  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::lazy_argument,
  "lazy_argument"
)

#endif

