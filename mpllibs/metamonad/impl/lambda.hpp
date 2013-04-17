#ifndef MPLLIBS_METAMONAD_IMPL_LAMBDA_HPP
#define MPLLIBS_METAMONAD_IMPL_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/unused_arg.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/first.hpp>
#include <mpllibs/metamonad/second.hpp>
#include <mpllibs/metamonad/pair.hpp>
#include <mpllibs/metamonad/is_same.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/contains.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      struct lambda_impl_step : tmp_value<lambda_impl_step>
      {
        // MPLLIBS_METAFUNCTION depends on it
        template <class State, class T>
        struct apply :
          pair<
            boost::mpl::pop_front<typename first<State>::type>,
            if_<
              is_same<boost::mpl::front<typename first<State>::type>, _>,
              second<State>,
              let<
                boost::mpl::front<typename first<State>::type>,
                syntax<T>,
                second<State>
              >
            >
          >
        {};
      };

      template <class State>
      struct lambda_impl;

      template <class State>
      struct lambda_maybe_eval :
        if_<
          boost::mpl::empty<typename first<State>::type>,
          eval_syntax<second<State> >,
          lambda_impl<State>
        >::type
      {};

      template <class State>
      struct lambda_impl : tmp_value<lambda_impl<State> >
      {
        template <
          BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
            BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
            class T,
            boost::mpl::na
          )
        >
        struct apply :
          lambda_maybe_eval<
            boost::mpl::fold<
              boost::mpl::vector<
                BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, T)
              >,
              State,
              lambda_impl_step
            >
          >
        {};
      };

      template <class A, class E1, class State>
      struct
        let_impl<A, E1, lambda_impl<State> > :
          lambda_impl<
            pair<
              first<State>,
              if_<
                boost::mpl::contains<typename first<State>::type, A>,
                second<State>,
                let_in_syntax<A, E1, second<State> >
              >
            >
          >
      {};
    }
  }
}

#endif

