#ifndef MPLLIBS_METAMONAD_STATE_HPP
#define MPLLIBS_METAMONAD_STATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/make_mpl_lambda.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>
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
      struct s;

      MPLLIBS_METAFUNCTION_CLASS(return_, (T))
      ((returns<lambda<s, boost::mpl::pair<T, s> > >));
      
      MPLLIBS_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        lambda<s,
          lazy<
            boost::mpl::apply_wrap1<
              make_mpl_lambda<
                boost::mpl::apply_wrap1<
                  make_mpl_lambda<F>,
                  boost::mpl::first<
                    boost::mpl::apply_wrap1<make_mpl_lambda<A>, s>
                  >
                >
              >,
              boost::mpl::second<
                boost::mpl::apply_wrap1<make_mpl_lambda<A>, s>
              >
            >
          >
        >
      ));
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

