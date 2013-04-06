#ifndef MPLLIBS_METAMONAD_MAYBE_HPP
#define MPLLIBS_METAMONAD_MAYBE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/maybe.hpp>

#include <mpllibs/metamonad/mappend.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct monad<maybe_tag<T> > : monad_defaults<maybe_tag<T> >
    {
      typedef lambda_c<x, just<x> > return_;
      
      typedef
        lambda_c<a, f,
          eval_case< a,
            matches_c<nothing, a>,
            matches_c<just<x>, apply<f, x> >
          >
        >
        bind;

      typedef lambda_c<_, nothing> fail;
    };

    template <class T>
    struct monad_plus<maybe_tag<T> >
    {
      typedef nothing mzero;

      typedef
        lambda_c<a, b,
          eval_case< a,
            matches_c<nothing, b>,
            matches_c<_,       a>
          >
        >
        mplus;
    };

    template <class T>
    struct monoid<maybe_tag<T> > : monoid_defaults<maybe_tag<T> >
    {
      typedef nothing mempty;

      typedef
        lambda_c<a, b,
          eval_case< a,
            matches_c<nothing, b>,
            matches_c<just<c>,
              eval_case< b,
                matches_c<nothing, a>,
                matches_c<just<d>, just<mpllibs::metamonad::mappend<T, c, d> > >
              >
            >
          >
        >
        mappend;
    };
  }
}

#endif

