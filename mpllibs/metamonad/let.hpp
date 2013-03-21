#ifndef MPLLIBS_METAMONAD_LET_HPP
#define MPLLIBS_METAMONAD_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/let.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/var.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      template <class A, class E1, class E2>
      struct strict_let;

      template <class A, class E1, class E2>
      struct strict_let<var<A>, syntax<E1>, syntax<E2> > :
        syntax<typename impl::let_in_syntax<var<A>, E1, E2>::type>
      {};
    }

    // MPLLIBS_LAZY_METAFUNCTION depends on it
    template <class A, class E1, class E2>
    struct let :
      impl::strict_let<typename A::type, typename E1::type, typename E2::type>
    {};

    namespace impl
    {
      template <class A, class E1a, class E1b, class E2>
      struct let_impl<A, E1a, let<A, E1b, E2> > :
        returns<let<A, E1b, E2> >
      {};
    }
  }
}

#endif

