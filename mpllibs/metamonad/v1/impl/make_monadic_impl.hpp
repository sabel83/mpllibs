#ifndef MPLLIBS_METAMONAD_V1_IMPL_MAKE_MONADIC_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MAKE_MONADIC_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/make_monadic_c.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class MonadTag, class Expr>
        struct make_monadic_impl;

        template <class MonadTag, class Expr>
        struct make_monadic_impl<MonadTag, syntax<Expr> > :
          make_monadic_c<MonadTag, Expr>
        {};
      }
    }
  }
}

#endif

