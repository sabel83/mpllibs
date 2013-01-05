#ifndef MPLLIBS_METAMONAD_LAMBDA_HPP
#define MPLLIBS_METAMONAD_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/lambda.hpp>

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/fold.hpp>

#include <boost/type_traits.hpp>

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
        template <class State, class T>
        struct apply :
          boost::mpl::eval_if<
            typename boost::is_same<lambda_no_arg, T>::type,
            State,
            lazy<
              boost::mpl::pair<
                boost::mpl::pop_front<boost::mpl::first<already_lazy<State> > >,
                let<
                  boost::mpl::front<boost::mpl::first<already_lazy<State> > >,
                  already_lazy<T>,
                  boost::mpl::second<already_lazy<State> >
                >
              >
            >
          >
        {};
      };

      template <class State>
      struct lambda_impl :
        boost::mpl::if_<
          typename boost::mpl::empty<
            typename boost::mpl::first<State>::type
          >::type,
          typename boost::mpl::second<State>::type,
          tmp_value<lambda_impl<State> >
        >::type
      {
        template <
          BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
            BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
            class T,
            lambda_no_arg
          )
        >
        struct apply :
          lambda_impl<
            typename boost::mpl::fold<
              boost::mpl::vector<
                BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, T)
              >,
              State,
              lambda_impl_step
            >::type
          >
        {};
      };
    }

    #ifdef MPLLIBS_LAMBDA_CASE
      #error MPLLIBS_LAMBDA_CASE already defined
    #endif
    #define MPLLIBS_LAMBDA_CASE(z, n, unused) \
      template < \
        BOOST_PP_ENUM_PARAMS(n, class T) \
        BOOST_PP_COMMA_IF(n) class F \
      > \
      struct \
        lambda< \
          BOOST_PP_ENUM_PARAMS(n, T) \
          BOOST_PP_COMMA_IF(n) F, \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
            impl::lambda_no_arg BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : \
        impl::lambda_impl< \
          boost::mpl::pair< \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, T)>, \
            F \
          > \
        > \
      {};

    BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_LAMBDA_CASE, ~)

    #undef MPLLIBS_LAMBDA_CASE

    template <class T>
    struct lazy;

    template <>
    struct lazy<impl::lambda_no_arg> : returns<impl::lambda_no_arg> {};
  }
}

#endif

