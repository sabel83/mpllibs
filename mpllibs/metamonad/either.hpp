#ifndef MPLLIBS_METAMONAD_EITHER_HPP
#define MPLLIBS_METAMONAD_EITHER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/case.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DATA(either, 2, ((left, 1))((right, 1)));
    
    template <class L, class R>
    struct monad<either_tag<L, R> > : monad_defaults<either_tag<L, R> >
    {
      MPLLIBS_LAZY_METAFUNCTION_CLASS(return_, (T)) ((right<T>));
      
      MPLLIBS_LAZY_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        case_< A,
          matches<left<_>,        returns<A> >,
          matches<right<var<x> >, boost::mpl::apply<F, x> >
        >
      ));

      MPLLIBS_LAZY_METAFUNCTION_CLASS(fail, (S)) ((left<S>));
    };
  }
}

#endif

