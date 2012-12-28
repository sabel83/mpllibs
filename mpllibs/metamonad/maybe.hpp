#ifndef MPLLIBS_METAMONAD_MAYBE_HPP
#define MPLLIBS_METAMONAD_MAYBE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/maybe.hpp>

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/case.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class T>
    struct monad<maybe_tag<T> > : monad_defaults<maybe_tag<T> >
    {
      MPLLIBS_LAZY_METAFUNCTION_CLASS(return_, (X)) ((just<X>));
      
      MPLLIBS_LAZY_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        case_< A,
          matches<nothing,       returns<A> >,
          matches<just<var<x> >, boost::mpl::apply<F, x> >
        >
      ));

      MPLLIBS_LAZY_METAFUNCTION_CLASS(fail, (S)) ((nothing));
    };

    template <class T>
    struct monad_plus<maybe_tag<T> >
    {
      typedef nothing mzero;

      MPLLIBS_LAZY_METAFUNCTION_CLASS(mplus, (A)(B))
      ((
        case_< A,
          matches<nothing, B>,
          matches<_,       A>
        >
      ));
    };

    template <class T>
    struct monoid<maybe_tag<T> > : monoid_defaults<maybe_tag<T> >
    {
      typedef nothing mempty;

      MPLLIBS_LAZY_METAFUNCTION_CLASS(mappend, (A)(B))
      ((
        case_< A,
          matches< nothing,
            returns<B>
          >,
          matches< just<var<a> >,
            case_< B,
              matches< nothing,
                returns<A>
              >,
              matches< just<var<b> >,
                lazy<
                  just<
                    boost::mpl::apply_wrap2<
                      typename monoid<T>::mappend,
                      already_lazy<a>,
                      already_lazy<b>
                    >
                  >
                >
              >
            >
          >
        >
      ));
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::maybe_tag,
  "maybe_tag"
)

#endif

