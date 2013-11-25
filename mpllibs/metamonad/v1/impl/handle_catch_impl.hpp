#ifndef MPLLIBS_METAMONAD_V1_IMPL_HANDLE_CATCH_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_HANDLE_CATCH_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/exception.hpp>
#include <mpllibs/metamonad/v1/eval_let.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class E, class N, class Pred, class Body>
        struct handle_catch_impl :
          if_<
            eval_let<N, syntax<E>, Pred>,
            pair<boost::mpl::false_, eval_let<N, syntax<E>, Body> >,
            pair<boost::mpl::true_, exception<E> >
          >
        {};
      }
    }
  }
}

#endif

