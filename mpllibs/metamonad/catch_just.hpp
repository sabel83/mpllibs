#ifndef MPLLIBS_METAMONAD_CATCH_JUST_HPP
#define MPLLIBS_METAMONAD_CATCH_JUST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/apply.hpp>

namespace mpllibs
{
  namespace metamonad
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

#endif

