#ifndef MPLLIBS_METAMONAD_V1_EITHER_HPP
#define MPLLIBS_METAMONAD_V1_EITHER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/either.hpp>
#include <mpllibs/metamonad/v1/fwd/monad.hpp>
#include <mpllibs/metamonad/v1/data.hpp>
#include <mpllibs/metamonad/v1/eval_case.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_DATA(either, 2, ((left, 1))((right, 1)));
      
      template <class L, class R>
      struct monad<either_tag<L, R> > : monad_defaults<either_tag<L, R> >
      {
        typedef right<> return_;
        
        typedef
          lambda_c<a, f,
            eval_case< a,
              matches_c<left<_>,  a>,
              matches_c<right<x>, apply<f, x> >
            >
          >
          bind;

        typedef left<> fail;
      };
    }
  }
}

#endif

