#ifndef MPLLIBS_METAMONAD_LAMBDA_C_HPP
#define MPLLIBS_METAMONAD_LAMBDA_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/lambda.hpp>
#include <mpllibs/metamonad/if.hpp>
#include <mpllibs/metamonad/pair.hpp>

#include <boost/mpl/contains.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
        class T,
        boost::mpl::na
      ),
      class T = boost::mpl::na // for the body
    >
    struct lambda_c;

    #ifdef MPLLIBS_LAMBDA_CASE
      #error MPLLIBS_LAMBDA_CASE already defined
    #endif
    #define MPLLIBS_LAMBDA_CASE(z, n, unused) \
      template < \
        BOOST_PP_ENUM_PARAMS(n, class T) \
        BOOST_PP_COMMA_IF(n) class F \
      > \
      struct \
        lambda_c< \
          BOOST_PP_ENUM_PARAMS(n, T) \
          BOOST_PP_COMMA_IF(n) F, \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
            boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : \
        impl::lambda_impl< \
          pair< \
            boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, T)>, \
            syntax<F> \
          > \
        > \
      {};

    BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_LAMBDA_CASE, ~)

    #undef MPLLIBS_LAMBDA_CASE

    namespace impl
    {
      // lambda_c and let
      #ifdef MPLLIBS_LET_LAMBDA
        #error MPLLIBS_LET_LAMBDA already defined
      #endif
      #define MPLLIBS_LET_LAMBDA(z, n, unused) \
        template < \
          class A, \
          class E1, \
          BOOST_PP_ENUM_PARAMS(n, class T) \
          BOOST_PP_COMMA_IF(n) class B \
        > \
        struct \
          let_impl< \
            A, \
            E1, \
            lambda_c< \
              BOOST_PP_ENUM_PARAMS(n, T) \
              BOOST_PP_COMMA_IF(n) B \
              BOOST_PP_COMMA_IF( \
                BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n) \
              ) \
              BOOST_PP_ENUM( \
                BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
                boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
                ~ \
              ) \
            > \
          > : \
            returns< \
              lambda_c< \
                BOOST_PP_ENUM_PARAMS(n, T) BOOST_PP_COMMA_IF(n) \
                typename if_< \
                  boost::mpl::contains< \
                    boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, T)>, \
                    A \
                  >, \
                  returns<B>, \
                  let_in_syntax<A, E1, B> \
                >::type \
              > \
            > \
        {};

      BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_LET_LAMBDA, ~)

      #undef MPLLIBS_LET_LAMBDA
    }
  }
}

#endif

