#ifndef MPLLIBS_METAMONAD_LETREC_HPP
#define MPLLIBS_METAMONAD_LETREC_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct letrec :
      let<A, syntax<lazy_protect_args<eval_syntax<letrec<A, E1, E1> > > >, E2>
    {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, mpllibs::metamonad::letrec, "letrec")

#endif

