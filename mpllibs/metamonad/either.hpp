#ifndef MPLLIBS_METAMONAD_EITHER_HPP
#define MPLLIBS_METAMONAD_EITHER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/lambda.hpp>
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
      typedef lambda_c<t, right<t> > return_;
      
      typedef
        lambda_c<a, f,
          eval_case< a,
            matches_c<left<_>,  a>,
            matches_c<right<x>, boost::mpl::apply<f, x> >
          >
        >
        bind;

      typedef lambda_c<t, left<t> > fail;
    };
  }
}

#endif

