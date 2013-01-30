#ifndef MPLLIBS_METAMONAD_LETREC_C_HPP
#define MPLLIBS_METAMONAD_LETREC_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/letrec.hpp>
#include <mpllibs/metamonad/syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct letrec_c : letrec<A, syntax<E1>, syntax<E2> > {};
  }
}

#endif

