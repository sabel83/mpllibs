#ifndef MPLLIBS_METAMONAD_V1_ALREADY_MONADIC_HPP
#define MPLLIBS_METAMONAD_V1_ALREADY_MONADIC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/already_monadic.hpp>
#include <mpllibs/metamonad/v1/fwd/make_monadic_c.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class T>
      struct already_monadic : tmp_value<already_monadic<T> > {};

      template <class MonadTag, class Expr>
      struct make_monadic_c<MonadTag, already_monadic<Expr> > : Expr {};
    }
  }
}

#endif

