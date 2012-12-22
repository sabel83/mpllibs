#ifndef MPLLIBS_METAMONAD_MAYBE_HPP
#define MPLLIBS_METAMONAD_MAYBE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/just.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>
#include <mpllibs/metamonad/nothing.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/monad_plus.hpp>
#include <mpllibs/metamonad/monoid.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(maybe_tag, (T)) ((tmp_tag<maybe_tag<T> >));
    
    template <class T>
    struct monad<maybe_tag<T> > : monad_defaults<maybe_tag<T> >
    {
      MPLLIBS_METAFUNCTION_CLASS(return_, (X)) ((just<X>));
      
      MPLLIBS_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        boost::mpl::eval_if<
          is_nothing<A>,
          boost::mpl::identity<A>,
          lazy<boost::mpl::apply<F, get_data<A> > >
        >
      ));

      MPLLIBS_METAFUNCTION_CLASS(fail, (S)) ((nothing));
    };

    template <class T>
    struct monad_plus<maybe_tag<T> >
    {
      typedef nothing mzero;

      MPLLIBS_METAFUNCTION_CLASS(mplus, (A)(B))
      ((boost::mpl::if_<is_nothing<A>, B, A>));
    };

    template <class T>
    struct monoid<maybe_tag<T> > : monoid_defaults<maybe_tag<T> >
    {
      typedef nothing mempty;

      MPLLIBS_METAFUNCTION_CLASS(mappend, (A)(B))
      ((
        boost::mpl::eval_if<
          typename is_nothing<A>::type,
          boost::mpl::identity<B>,
          boost::mpl::eval_if<
            typename is_nothing<B>::type,
            boost::mpl::identity<A>,
            lazy<
              just<
                boost::mpl::apply_wrap2<
                  typename monoid<T>::mappend,
                  get_data<A>,
                  get_data<B>
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

