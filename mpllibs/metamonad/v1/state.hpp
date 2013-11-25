#ifndef MPLLIBS_METAMONAD_V1_STATE_HPP
#define MPLLIBS_METAMONAD_V1_STATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/state_tag.hpp>
#include <mpllibs/metamonad/v1/monad.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/eval_match_let_c.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <>
      struct monad<state_tag> : monad_defaults<state_tag>
      {
        typedef pair<> return_;

        typedef
          lambda_c<a, f, s,
            eval_match_let_c<pair<t, u>, apply<a, s>, apply<apply<f, t>, u> >
          >
          bind;
      };
    }
  }
}

#endif

