#ifndef MPLLIBS_METAMONAD_MAKE_MONADIC_HPP
#define MPLLIBS_METAMONAD_MAKE_MONADIC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/make_monadic_c.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class MonadTag, class Expr>
    struct make_monadic_c;

    template <class MonadTag, class Expr>
    struct make_monadic_impl;

    template <class MonadTag, class Expr>
    struct make_monadic_impl<MonadTag, syntax<Expr> > :
      make_monadic_c<MonadTag, Expr>
    {};

    template <class MonadTag, class Expr>
    struct make_monadic :
      make_monadic_impl<typename MonadTag::type, typename Expr::type>
    {};
  }
}

#endif

