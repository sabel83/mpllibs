#ifndef MPLLIBS_METAMONAD_LAMBDA_HPP
#define MPLLIBS_METAMONAD_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/lambda.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
        class T,
        impl::lambda_no_arg
      ),
      class T = impl::lambda_no_arg // for the body
    >
    struct lambda;

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
      {}; \
      \
      template < \
        class A, \
        class E1, \
        BOOST_PP_ENUM_PARAMS(n, class T) \
        BOOST_PP_COMMA_IF(n) class F \
      > \
      struct \
        let_impl< \
          A, \
          E1, \
          lambda< \
            BOOST_PP_ENUM_PARAMS(n, T) \
            BOOST_PP_COMMA_IF(n) F, \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
              impl::lambda_no_arg BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > : \
          lambda< \
            BOOST_PP_ENUM_PARAMS(n, T) BOOST_PP_COMMA_IF(n) \
            typename boost::mpl::eval_if< \
              typename boost::mpl::contains< \
                boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, T)>, \
                A \
              >::type, \
              returns<F>, \
              let_in_syntax<A, E1, F> \
            >::type \
          > \
      {};

    BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_LAMBDA_CASE, ~)

    #undef MPLLIBS_LAMBDA_CASE
  }
}

#endif

