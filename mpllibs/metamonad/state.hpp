#ifndef MPLLIBS_METAMONAD_STATE_HPP
#define MPLLIBS_METAMONAD_STATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/monad.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/pair.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_TAG(state_tag)
    
    template <>
    struct monad<state_tag> : monad_defaults<state_tag>
    {
      struct return_ : tmp_value<return_>
      {
        template <class T>
        struct apply
        {
          struct type : tmp_value<type>
          {
            template <class S>
            struct apply : boost::mpl::pair<T, S> {};
          };
        };
      };
      
      struct bind : tmp_value<bind>
      {
      private:
        template <class A, class F>
        struct impl : tmp_value<impl<A, F> >
        {
          template <class S>
          struct apply
          {
          private:
            typedef typename boost::mpl::apply<A, S>::type apply_first;
            typedef typename apply_first::first new_value;
            typedef typename apply_first::second new_state;
          public:
            typedef
              typename boost::mpl::apply<
                typename boost::mpl::apply<F, new_value>::type,
                new_state
              >::type
              type;
          };
        };
      public:
        template <class A, class F>
        struct apply : impl<A, F> {};
      };
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

