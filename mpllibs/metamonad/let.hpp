#ifndef MPLLIBS_METAMONAD_LET_HPP
#define MPLLIBS_METAMONAD_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/let.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct let_;

    template <class A, class E1, class E2>
    struct let_<A, syntax<E1>, syntax<E2> > :
      syntax<typename impl::let_in_syntax<A, E1, E2>::type>
    {};

    MPLLIBS_METAFUNCTION(let, (A)(E1)(E2))
    ((let_<typename A::type, typename E1::type, typename E2::type>));
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, mpllibs::metamonad::let, "let")

#endif

