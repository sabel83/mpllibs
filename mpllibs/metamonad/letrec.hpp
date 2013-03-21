#ifndef MPLLIBS_METAMONAD_LETREC_HPP
#define MPLLIBS_METAMONAD_LETREC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct letrec : let<A, syntax<eval_syntax<letrec<A, E1, E1> > >, E2> {};

    namespace impl
    {
      template <class A, class E1a, class E1b, class E2>
      struct let_impl<A, E1a, letrec<A, E1b, E2> > :
        returns<letrec<A, E1b, E2> >
      {};
    }
  }
}

#endif

