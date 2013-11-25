#ifndef MPLLIBS_METAMONAD_V1_MAKE_MONADIC_HPP
#define MPLLIBS_METAMONAD_V1_MAKE_MONADIC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/make_monadic.hpp>
#include <mpllibs/metamonad/v1/impl/make_monadic_impl.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class MonadTag, class Expr>
      struct make_monadic :
        impl::make_monadic_impl<typename MonadTag::type, typename Expr::type>
      {};
    }
  }
}

#endif

