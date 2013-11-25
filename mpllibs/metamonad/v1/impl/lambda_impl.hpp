#ifndef MPLLIBS_METAMONAD_V1_IMPL_LAMBDA_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LAMBDA_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/fwd/lambda_impl.hpp>
#include <mpllibs/metamonad/v1/impl/fwd/let_impl.hpp>
#include <mpllibs/metamonad/v1/impl/lambda_maybe_eval.hpp>
#include <mpllibs/metamonad/v1/impl/lambda_impl_step.hpp>
#include <mpllibs/metamonad/v1/impl/let_in_syntax.hpp>

#include <mpllibs/metamonad/v1/tmp_value.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/contains.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
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
}

#endif

