#ifndef MPLLIBS_METAMONAD_V1_CATCH_C_HPP
#define MPLLIBS_METAMONAD_V1_CATCH_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/catch_c.hpp>
#include <mpllibs/metamonad/v1/impl/fwd/let_impl.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class Name, class Pred, class Body>
      struct catch_c : tmp_value<catch_c<Name, Pred, Body> > {};

      namespace impl
      {
        template <class A, class E1, class Pred, class Body>
        struct let_impl<A, E1, catch_c<A, Pred, Body> > :
          catch_c<A, Pred, Body>
        {};
      }
    }
  }
}

#endif

