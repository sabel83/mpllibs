#ifndef MPLLIBS_METAMONAD_V1_HANDLE_CATCH_HPP
#define MPLLIBS_METAMONAD_V1_HANDLE_CATCH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/catch_.hpp>
#include <mpllibs/metamonad/v1/fwd/catch_c.hpp>

#include <mpllibs/metamonad/v1/impl/handle_catch_impl.hpp>

#include <mpllibs/metamonad/v1/syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class E, class Catch>
        struct handle_catch;

        template <class E, class N, class Pred, class Body>
        struct handle_catch<E, catch_c<N, Pred, Body> > :
          handle_catch_impl<
            typename E::type,
            typename N::type,
            syntax<Pred>,
            syntax<Body>
          >
        {};

        template <class E, class N, class Pred, class Body>
        struct handle_catch<E, catch_<N, Pred, Body> > :
          handle_catch_impl<
            typename E::type,
            typename N::type,
            typename Pred::type,
            typename Body::type
          >
        {};
      }
    }
  }
}

#endif

