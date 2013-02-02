#ifndef MPLLIBS_METAMONAD_STATE_HPP
#define MPLLIBS_METAMONAD_STATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/eval_match_let_c.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/pair.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct state_tag : tmp_tag<state_tag> {};
    
    template <>
    struct monad<state_tag> : monad_defaults<state_tag>
    {
      typedef lambda_c<t, s, boost::mpl::pair<t, s> > return_;

      typedef
        lambda_c<a, f, s,
          eval_match_let_c<
            boost::mpl::pair<t, u>,
            lazy<boost::mpl::apply_wrap1<a, s> >,
            lazy<boost::mpl::apply_wrap1<boost::mpl::apply_wrap1<f, t>, u> >
          >
        >
        bind;
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::state_tag>::bind,
  "monad<state_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::state_tag>::return_,
  "monad<state_tag>::return_"
)

#endif

