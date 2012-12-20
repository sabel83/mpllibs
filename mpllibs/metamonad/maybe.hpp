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
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct maybe_tag : tmp_tag<maybe_tag> {};
    
    template <>
    struct monad<maybe_tag> : monad_defaults<maybe_tag>
    {
      MPLLIBS_METAFUNCTION_CLASS(return_, (T)) ((just<T>));
      
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
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::maybe_tag>::bind,
  "monad<maybe_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::maybe_tag>::fail,
  "monad<maybe_tag>::fail"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::maybe_tag>::return_,
  "monad<maybe_tag>::return_"
)

#endif

