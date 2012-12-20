#ifndef MPLLIBS_METAMONAD_EITHER_HPP
#define MPLLIBS_METAMONAD_EITHER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/left.hpp>
#include <mpllibs/metamonad/right.hpp>
#include <mpllibs/metamonad/is_left.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct either_tag : tmp_tag<either_tag> {};
    
    template <>
    struct monad<either_tag> : monad_defaults<either_tag>
    {
      MPLLIBS_METAFUNCTION_CLASS(return_, (T)) ((right<T>));
      
      MPLLIBS_METAFUNCTION_CLASS(bind, (A)(F))
      ((
        boost::mpl::eval_if<
          is_left<A>,
          boost::mpl::identity<A>,
          boost::mpl::apply<F, typename get_data<A>::type>
        >
      ));

      MPLLIBS_METAFUNCTION_CLASS(fail, (S)) ((left<S>));
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::either_tag>::bind,
  "monad<either_tag>::bind"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::either_tag>::fail,
  "monad<either_tag>::fail"
)

MPLLIBS_DEFINE_TO_STREAM_FOR_TYPE(
  mpllibs::metamonad::monad<mpllibs::metamonad::either_tag>::return_,
  "monad<either_tag>::return_"
)

#endif

