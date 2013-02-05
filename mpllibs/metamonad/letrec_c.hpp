#ifndef MPLLIBS_METAMONAD_LETREC_C_HPP
#define MPLLIBS_METAMONAD_LETREC_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/letrec.hpp>
#include <mpllibs/metamonad/eval_let_c.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct letrec_c : letrec<A, syntax<E1>, syntax<E2> > {};

    namespace impl
    {
      template <class A, class E1a, class E1b, class E2>
      struct let_impl<A, E1a, letrec_c<A, E1b, E2> > :
        returns<letrec_c<A, typename eval_let_c<A, E1a, E1b>::type, E2> >
      {};
    }
  }
}

#endif

