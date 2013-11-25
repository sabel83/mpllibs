#ifndef MPLLIBS_METAMONAD_V1_CATCH_JUST_HPP
#define MPLLIBS_METAMONAD_V1_CATCH_JUST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/eval_case.hpp>
#include <mpllibs/metamonad/v1/exception.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class E, class Pred, class Handler>
      struct catch_just :
        eval_case<E,
          matches_c<exception<e>, if_<apply<Pred, e>, apply<Handler, e>, E> >,
          matches_c<_, E>
        >
      {};
    }
  }
}

#endif

