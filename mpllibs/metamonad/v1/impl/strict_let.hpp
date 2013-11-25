#ifndef MPLLIBS_METAMONAD_V1_STRICT_LET_HPP
#define MPLLIBS_METAMONAD_V1_STRICT_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/let_in_syntax.hpp>
#include <mpllibs/metamonad/v1/var.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
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
    }
  }
}

#endif

