#ifndef MPLLIBS_METAMONAD_V1_IMPL_LET_IN_SYNTAX_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LET_IN_SYNTAX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/fwd/let_in_syntax.hpp>
#include <mpllibs/metamonad/v1/impl/let_impl.hpp>

#include <mpllibs/metamonad/v1/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class A, class E1, class E2>
        struct let_in_syntax : let_impl<A, E1, E2> {};

        template <class A, class E1>
        struct let_in_syntax<A, E1, A> : returns<E1> {};
      }
    }
  }
}

#endif

