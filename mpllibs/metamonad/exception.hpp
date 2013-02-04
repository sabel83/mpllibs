#ifndef MPLLIBS_METAMONAD_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/eval_case.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    /*
     * The Exception monad
     * This is modeled along the Either monad of Haskell
     *
     * A monadic value is either:
     *  - An exception
     *  - Any other value
     *
     */
    typedef exception_tag exception_monad;
    
    /*
     * return
     */
    template <class Tag>
    struct monad;

    template <>
    struct monad<exception_tag> : monad_defaults<exception_tag>
    {
      typedef lambda_c<t, t> return_;
      
      typedef
        lambda_c<a, f,
          eval_case< a,
            matches_c<exception<_>, a>,
            matches_c<_, boost::mpl::apply1<f, a> >
          >
        >
        bind;
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::exception_tag>::bind,
  "monad<exception_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::exception_tag>::fail,
  "monad<exception_tag>::fail"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::exception_tag>::return_,
  "monad<exception_tag>::return_"
)

#endif

