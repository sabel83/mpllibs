#ifndef MPLLIBS_METAMONAD_LET_HPP
#define MPLLIBS_METAMONAD_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/impl/lambda.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class A, class E1, class E2>
    struct let_impl0;

    template <class A, class E1, class E2>
    struct let_impl1 : let_impl0<A, E1, E2> {};

    template <class A, class E1, class E2>
    struct let : let_impl1<A, E1, E2> {};

    template <class A, class E1>
    struct let<A, E1, A> : returns<E1> {};

    
    // let_impl assumes, that let_impl<A, E1, A> is never instantiated
    template <class A, class E1, class E2>
    struct let_impl0 : returns<E2> {};

    template <class A, class E1a, class E1b, class E2>
    struct let_impl0<A, E1a, let<A, E1b, E2> > :
      returns<let<A, E1b, E2> >
    {};

    template <class A, class E1, class E2>
    struct letrec;

    template <class A, class E1a, class E1b, class E2>
    struct let_impl0<A, E1a, letrec<A, E1b, E2> > :
      returns<letrec<A, E1b, E2> >
    {};

    #ifdef MPLLIBS_LET_LAMBDA_SPEC
      #error MPLLIBS_LET_LAMBDA_SPEC already defined
    #endif
    #define MPLLIBS_LET_LAMBDA_SPEC(z, i, n) \
      template < \
        class A, \
        class E1, \
        BOOST_PP_ENUM_PARAMS(i, class T) \
        BOOST_PP_COMMA_IF(i) \
        BOOST_PP_ENUM_PARAMS(BOOST_PP_SUB(n, i), class U) \
      > \
      struct \
        let_impl1< \
          A, \
          E1, \
          lambda< \
            BOOST_PP_ENUM_PARAMS(i, T) \
            BOOST_PP_COMMA_IF(i) A, \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_SUB(n, i), U) \
            BOOST_PP_COMMA_IF( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n) \
            ) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
              impl::lambda_no_arg BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > : \
          returns< \
            lambda< \
              BOOST_PP_ENUM_PARAMS(i, T) \
              BOOST_PP_COMMA_IF(i) A, \
              BOOST_PP_ENUM_PARAMS(BOOST_PP_SUB(n, i), U) \
            > \
          > \
      {};

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
        let_impl0< \
          A, \
          E1, \
          lambda< \
            BOOST_PP_ENUM_PARAMS(n, T) \
            BOOST_PP_COMMA_IF(n) B \
            BOOST_PP_COMMA_IF( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n) \
            ) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, n), \
              impl::lambda_no_arg BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > : \
        returns< \
          lambda< \
            BOOST_PP_ENUM_PARAMS(n, T) \
            BOOST_PP_COMMA_IF(n) typename let<A, E1, B>::type \
          > \
        > \
      {}; \
      \
      BOOST_PP_REPEAT(BOOST_PP_SUB(n, 1), MPLLIBS_LET_LAMBDA_SPEC, n)
    // There is a BOOST_PP_SUB(n, 1) to avoid confusion for
    // let<x, ..., lambda<..., ..., ..., x>>

    BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_LET_LAMBDA, ~)

    #undef MPLLIBS_LET_LAMBDA
    #undef MPLLIBS_LET_LAMBDA_SPEC



    #ifndef MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT
      #define MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT 10
    #endif
    
    #ifdef MPLLIBS_LET_CLASS
      #error MPLLIBS_LET_CLASS alread defined
    #endif
    #define MPLLIBS_LET_CLASS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) class
    
    #ifdef MPLLIBS_LET_REC_CASE
      #error MPLLIBS_LET_REC_CASE alread defined
    #endif
    #define MPLLIBS_LET_REC_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(n) typename let<A, E1, X##n>::type

    #ifdef MPLLIBS_LET_TEMPLATE_CASE
      #error MPLLIBS_LET_TEMPLATE_CASE already defined
    #endif
    #define MPLLIBS_LET_TEMPLATE_CASE(z, n, unused) \
      template < \
        class A, \
        class E1, \
        template<BOOST_PP_REPEAT(n, MPLLIBS_LET_CLASS, ~) > class T, \
        BOOST_PP_ENUM_PARAMS(n, class X) \
      > \
      struct let_impl0<A, E1, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
        mpllibs::metamonad::returns< \
          T<BOOST_PP_REPEAT(n, MPLLIBS_LET_REC_CASE, ~) > \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT,
      MPLLIBS_LET_TEMPLATE_CASE,
      ~
    )

    #undef MPLLIBS_LET_TEMPLATE_CASE
    #undef MPLLIBS_LET_CLASS
    #undef MPLLIBS_LET_REC_CASE
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(3, mpllibs::metamonad::let, "let")

#endif

