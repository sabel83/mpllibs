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
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/lazy_protect_args.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/lambda.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct monad<maybe_tag<T> > : monad_defaults<maybe_tag<T> >
    {
      typedef lambda<x, just<x> > return_;
      
      typedef
        lambda<a, f,
          eval_case< a,
            matches<nothing, returns<a> >,
            matches<just<x>, boost::mpl::apply<f, x> >
          >
        >
        bind;

      typedef lambda<_, nothing> fail;
    };

    template <class T>
    struct monad_plus<maybe_tag<T> >
    {
      typedef nothing mzero;

      typedef
        lambda<a, b,
          eval_case< a,
            matches<nothing, b>,
            matches<_,       a>
          >
        >
        mplus;
    };

    template <class T>
    struct monoid<maybe_tag<T> > : monoid_defaults<maybe_tag<T> >
    {
      typedef nothing mempty;

      typedef
        lambda<a, b,
          eval_case< a,
            matches< nothing,
              returns<b>
            >,
            matches< just<c>,
              eval_case< b,
                matches< nothing,
                  returns<a>
                >,
                matches< just<d>,
                  lazy<
                    just<
                      lazy_protect_args<mpllibs::metamonad::mappend<T, c, d> >
                    >
                  >
                >
              >
            >
          >
        >
        mappend;
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::maybe_tag,
  "maybe_tag"
)

#endif

