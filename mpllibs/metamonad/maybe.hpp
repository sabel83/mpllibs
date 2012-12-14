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

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct maybe_tag : tmp_tag<maybe_tag> {};
    
    template <>
    struct monad<maybe_tag> : monad_defaults<maybe_tag>
    {
      struct return_ : tmp_value<return_>
      {
        template <class T>
        struct apply : just<T> {};
      };
      
      struct bind : tmp_value<bind>
      {
      private:
        template <class A, class F>
        struct call_F : boost::mpl::apply<F, typename get_data<A>::type> {};
      public:
        template <class A, class F>
        struct apply :
          boost::mpl::if_<
            is_nothing<A>,
            boost::mpl::identity<A>,
            call_F<A, F>
          >::type
        {};
      };

      struct fail : tmp_value<fail>
      {
        template <class S>
        struct apply : nothing {};
      };
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

