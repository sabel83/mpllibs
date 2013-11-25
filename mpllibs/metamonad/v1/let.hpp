#ifndef MPLLIBS_METAMONAD_V1_LET_HPP
#define MPLLIBS_METAMONAD_V1_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/let.hpp>
#include <mpllibs/metamonad/v1/impl/fwd/let_impl.hpp>
#include <mpllibs/metamonad/v1/impl/strict_let.hpp>
#include <mpllibs/metamonad/v1/returns.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // MPLLIBS_V1_LAZY_METAFUNCTION depends on it
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
}

#endif

