#ifndef MPLLIBS_METAMONAD_DO__HPP
#define MPLLIBS_METAMONAD_DO__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/bind_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/return_.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    #ifndef MPLLIBS_DO_MAX_ARGUMENT
      #define MPLLIBS_DO_MAX_ARGUMENT 8
    #endif
    
    #if MPLLIBS_DO_MAX_ARGUMENT + 2 > MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT
      #error MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT not big enough
    #endif
    
    /*
     * Syntactic sugar
     */
    #ifdef MPLLIBS_DO
      #error MPLLIBS_DO already defined
    #endif
    #define MPLLIBS_DO mpllibs::metamonad::do_
    
    #ifdef MPLLIBS_SET
      #error MPLLIBS_SET already defined
    #endif
    #define MPLLIBS_SET mpllibs::metamonad::set
  
    #ifdef MPLLIBS_RETURN
      #error MPLLIBS_RETURN already defined
    #endif
    #define MPLLIBS_RETURN mpllibs::metamonad::do_return

    struct unused_do_argument;

    template <
      class Monad,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_DO_MAX_ARGUMENT,
        class E,
        unused_do_argument
      )
    >
    struct do_impl;
    
    /*
     * do_return
     */
    template <class>
    struct do_return;

    /*
     * do_return substitution
     */
    // I can't use let, because I should not stop at let expressions.
    // Nested do_'s are not important, since they should be used by
    // accessing a nested apply template, and do_substitute doesn't
    // recurse into that.
    // Using boost::mpl::apply and do_ together is not supported
    template <class Monad, class T>
    struct do_substitute : mpllibs::metamonad::util::id<T> {};

    template <class Monad, class T>
    struct do_substitute<Monad, do_return<T> > :
      mpllibs::metamonad::util::id<
        return_<Monad, typename do_substitute<Monad, T>::type>
      >
    {};
    
    // When an outer do_ has already substituted this do_return,
    // we need to re-substitute it. I couldn't find a way of preventing
    // substitution of inner do_'s do_returns.
    template <class Monad1, class Monad2, class T>
    struct do_substitute<Monad1, return_<Monad2, T> > :
      mpllibs::metamonad::util::id<
        return_<Monad1, typename do_substitute<Monad1, T>::type>
      >
    {};

    #ifdef MPLLIBS_DO_CLASS
      #error MPLLIBS_DO_CLASS alread defined
    #endif
    #define MPLLIBS_DO_CLASS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) class
    
    #ifdef MPLLIBS_DO_REC_CASE
      #error MPLLIBS_DO_REC_CASE alread defined
    #endif
    #define MPLLIBS_DO_REC_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(n) \
      typename do_substitute<Monad, X##n>::type

    #ifdef MPLLIBS_DO_TEMPLATE_CASE
      #error MPLLIBS_DO_TEMPLATE_CASE already defined
    #endif
    #define MPLLIBS_DO_TEMPLATE_CASE(z, n, unused) \
      template < \
        class Monad, \
        template<BOOST_PP_REPEAT(n, MPLLIBS_DO_CLASS, ~) > class T, \
        BOOST_PP_ENUM_PARAMS(n, class X) \
      > \
      struct do_substitute<Monad, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
        mpllibs::metamonad::util::id< \
          T< BOOST_PP_REPEAT(n, MPLLIBS_DO_REC_CASE, ~) > \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT,
      MPLLIBS_DO_TEMPLATE_CASE,
      ~
    )

    #undef MPLLIBS_DO_TEMPLATE_CASE
    #undef MPLLIBS_DO_CLASS
    #undef MPLLIBS_DO_REC_CASE

    /*
     * set
     */
    template <class Name, class F>
    struct set;

    /*
     * do1
     */
    // This case handles nullary metafunction elements of the do
    template <class Monad, class E>
    struct do1 : E {};

    template <class Monad, class Name, class F>
    struct do1<Monad, set<Name, F> >;
      // Error: last statement in a 'do' construct must be an expression.
      // Current way of error handling is not having an implementation.
      // It may be improved.
    
    /*
     * don
     */
     
    #ifdef MPLLIBS_DO_CLASS_CASE
      #error MPLLIBS_DO_CLASS_CASE already defined
    #endif
    #define MPLLIBS_DO_CLASS_CASE(z, n, unused) \
      , class E##n
    
    #ifdef MPLLIBS_DO_CLASS_USE_CASE
      #error MPLLIBS_DO_CLASS_USE_CASE already defined
    #endif
    #define MPLLIBS_DO_CLASS_USE_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) E##n

    #ifdef MPLLIBS_DO_CASE
      #error MPLLIBS_DO_CASE already defined
    #endif
    // I need at least one template argument. The "n"th case handles n+1 args.
    #define MPLLIBS_DO_CASE(z, n, unused) \
      template < \
        class Monad, \
        class T \
        BOOST_PP_REPEAT_FROM_TO(1, n, MPLLIBS_DO_CLASS_CASE, ~) \
      > \
      struct do##n : \
        boost::mpl::apply_wrap2< \
          bind__impl<Monad>, \
          typename T::type, \
          typename do_impl< \
            Monad, \
            BOOST_PP_REPEAT_FROM_TO(1, n, MPLLIBS_DO_CLASS_USE_CASE, ~) \
          >::type \
        > \
      {}; \
      \
      template < \
        class Monad, \
        class Name, \
        class Ex \
        BOOST_PP_REPEAT_FROM_TO(1, n, MPLLIBS_DO_CLASS_CASE, ~) \
      > \
      struct do##n< \
        Monad, \
        set<Name, Ex> \
        BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
        BOOST_PP_REPEAT_FROM_TO(1, n, MPLLIBS_DO_CLASS_USE_CASE, ~) \
      > : \
        boost::mpl::apply_wrap2< \
          bind_impl<Monad>, \
          typename do1<Monad, Ex>::type, \
          typename lambda< \
            Name, \
            do_impl< \
              Monad, \
              BOOST_PP_REPEAT_FROM_TO(1, n, MPLLIBS_DO_CLASS_USE_CASE, ~) \
            > \
          >::type \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(2, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_CASE, ~)
    
    #undef MPLLIBS_DO_CASE
    #undef MPLLIBS_DO_CLASS_USE_CASE
    #undef MPLLIBS_DO_CLASS_CASE
        
    /*
     * do_impl
     */
    #ifdef MPLLIBS_DO_UNUSED_PARAM
      #error MPLLIBS_DO_UNUSED_PARAM already defined
    #endif
    #define MPLLIBS_DO_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) unused_do_argument
    
    #ifdef MPLLIBS_DO_CASE
      #error MPLLIBS_DO_CASE already defined
    #endif
    #define MPLLIBS_DO_CASE(z, n, unused) \
      template <class Monad, BOOST_PP_ENUM_PARAMS(n, class E)> \
      struct do_impl< \
        Monad, \
        BOOST_PP_ENUM_PARAMS(n, E) BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(MPLLIBS_DO_MAX_ARGUMENT, n), \
          MPLLIBS_DO_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        do##n<Monad, BOOST_PP_ENUM_PARAMS(n, E)> \
      {};
  
    BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_CASE, ~)
    
    #undef MPLLIBS_DO_CASE
    #undef MPLLIBS_DO_UNUSED_PARAM
    
    /*
     * do_
     */
    #ifdef MPLLIBS_DO_ARG
      #error MPLLIBS_DO_ARG already defined
    #endif
    #define MPLLIBS_DO_ARG(z, n, unused) \
      , typename do_substitute<Monad, E##n>::type
    
    template <class Monad>
    struct do_
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_DO_MAX_ARGUMENT,
          class E,
          unused_do_argument
        )
      >
      struct apply :
        do_impl<
          Monad BOOST_PP_REPEAT(MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DO_ARG, ~)
        >
      {};
    };
    
    #undef MPLLIBS_DO_ARG
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, mpllibs::metamonad::do_, "MPLLIBS_DO");

#endif

