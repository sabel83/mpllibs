#ifndef MPLLIBS_METAMONAD_V1_ALREADY_LAZY_HPP
#define MPLLIBS_METAMONAD_V1_ALREADY_LAZY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/already_lazy.hpp>
#include <mpllibs/metamonad/v1/fwd/lazy.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(already_lazy, (AnglyExpr)) ((AnglyExpr));

      template <class AnglyExpr>
      struct lazy<already_lazy<AnglyExpr> > : returns<AnglyExpr> {};
    }
  }
}

#endif

