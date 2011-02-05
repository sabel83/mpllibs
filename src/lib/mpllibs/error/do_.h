#ifndef MPLLIBS_ERROR_DO__H
#define MPLLIBS_ERROR_DO__H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/lambda.h>
#include <mpllibs/error/bind_.h>
#include <mpllibs/error/bind.h>
#include <mpllibs/error/let.h>
#include <mpllibs/error/return_.h>

#include <boost/mpl/apply.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>

namespace mpllibs
{
  namespace error
  {
    #ifndef DO_MAX_ARGUMENT
      #define DO_MAX_ARGUMENT 8
    #endif
    
    #if DO_MAX_ARGUMENT + 2 > LET_MAX_TEMPLATE_ARGUMENT
      #error LET_MAX_TEMPLATE_ARGUMENT not big enough
    #endif
    
    /*
     * Syntactic sugar
     */
    #ifdef DO
      #error DO already defined
    #endif
    #define DO mpllibs::error::do_
    
    #ifdef SET
      #error SET already defined
    #endif
    #define SET mpllibs::error::set
  
    struct unused_do_argument;

    template <
      class monad,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        DO_MAX_ARGUMENT,
        class e,
        mpllibs::error::unused_do_argument
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
    // I can't use let, because I need to stop at nested do_'s
    // even though it is the same solution
    template <class monad, class t>
    struct do_substitute : mpllibs::error::util::id<t> {};
    
    template <class monad, class t>
    struct do_substitute<monad, do_return<t> > :
      mpllibs::error::util::id<mpllibs::error::return_<monad, t> >
    {};

    #ifdef DO_CLASS
      #error DO_CLASS alread defined
    #endif
    #define DO_CLASS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) class
    
    #ifdef DO_REC_CASE
      #error DO_REC_CASE alread defined
    #endif
    #define DO_REC_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(n) \
      typename mpllibs::error::do_substitute<monad, x##n>::type

    #ifdef DO_TEMPLATE_CASE
      #error DO_TEMPLATE_CASE already defined
    #endif
    #define DO_TEMPLATE_CASE(z, n, unused) \
      template < \
        class monad, \
        template<BOOST_PP_REPEAT(n, DO_CLASS, ~) > class t, \
        BOOST_PP_ENUM_PARAMS(n, class x) \
      > \
      struct do_substitute<monad, t<BOOST_PP_ENUM_PARAMS(n, x)> > : \
        mpllibs::error::util::id< t< BOOST_PP_REPEAT(n, DO_REC_CASE, ~) > > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(1, LET_MAX_TEMPLATE_ARGUMENT, DO_TEMPLATE_CASE, ~)

    #undef DO_TEMPLATE_CASE
    #undef DO_CLASS
    #undef DO_REC_CASE

    /*
     * set
     */
    template <class name, class f>
    struct set;

    /*
     * do1
     */
    // This case handles nullary metafunction elements of the do
    template <class monad, class e>
    struct do1 : e {};

    template <class monad, class name, class f>
    struct do1<monad, mpllibs::error::set<name, f> >;
      // Error: last statement in a 'do' construct must be an expression.
      // Current way of error handling is not having an implementation.
      // It may be improved.
    
    /*
     * don
     */
     
    #ifdef DO_CLASS_CASE
      #error DO_CLASS_CASE already defined
    #endif
    #define DO_CLASS_CASE(z, n, unused) \
      , class e##n
    
    #ifdef DO_CLASS_USE_CASE
      #error DO_CLASS_USE_CASE already defined
    #endif
    #define DO_CLASS_USE_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) e##n

    #ifdef DO_CASE
      #error DO_CASE already defined
    #endif
    // I need at least one template argument. The "n"th case handles n+1 args.
    #define DO_CASE(z, n, unused) \
      template < \
        class monad, \
        class t \
        BOOST_PP_REPEAT_FROM_TO(1, n, DO_CLASS_CASE, ~) \
      > \
      struct do##n : \
        boost::mpl::apply< \
          mpllibs::error::bind__impl<monad>, \
          typename t::type, \
          typename mpllibs::error::do_impl< \
            monad, \
            BOOST_PP_REPEAT_FROM_TO(1, n, DO_CLASS_USE_CASE, ~) \
          >::type \
        > \
      {}; \
      \
      template < \
        class monad, \
        class name, \
        class ex \
        BOOST_PP_REPEAT_FROM_TO(1, n, DO_CLASS_CASE, ~) \
      > \
      struct do##n< \
        monad, \
        mpllibs::error::set<name, ex> \
        BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) \
        BOOST_PP_REPEAT_FROM_TO(1, n, DO_CLASS_USE_CASE, ~) \
      > : \
        boost::mpl::apply< \
          mpllibs::error::bind_impl<monad>, \
          typename mpllibs::error::do1<monad, ex>::type, \
          typename mpllibs::error::lambda< \
            name, \
            mpllibs::error::do_impl< \
              monad, \
              BOOST_PP_REPEAT_FROM_TO(1, n, DO_CLASS_USE_CASE, ~) \
            > \
          >::type \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(2, DO_MAX_ARGUMENT, DO_CASE, ~)
    
    #undef DO_CASE
    #undef DO_CLASS_USE_CASE
    #undef DO_CLASS_CASE
        
    /*
     * do_impl
     */
    #ifdef DO_UNUSED_PARAM
      #error DO_UNUSED_PARAM already defined
    #endif
    #define DO_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) mpllibs::error::unused_do_argument
    
    #ifdef DO_CASE
      #error DO_CASE already defined
    #endif
    #define DO_CASE(z, n, unused) \
      template <class monad, BOOST_PP_ENUM_PARAMS(n, class e)> \
      struct do_impl< \
        monad, \
        BOOST_PP_ENUM_PARAMS(n, e) BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(DO_MAX_ARGUMENT, n), \
          DO_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        mpllibs::error::do##n<monad, BOOST_PP_ENUM_PARAMS(n, e)> \
      {};
  
    BOOST_PP_REPEAT_FROM_TO(1, DO_MAX_ARGUMENT, DO_CASE, ~)
    
    #undef DO_CASE
    #undef DO_UNUSED_PARAM
    
    /*
     * do_
     */
    #ifdef DO_ARG
      #error DO_ARG already defined
    #endif
    #define DO_ARG(z, n, unused) , typename do_substitute<monad, e##n>::type
    
    template <class monad>
    struct do_
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          DO_MAX_ARGUMENT,
          class e,
          mpllibs::error::unused_do_argument
        )
      >
      struct apply :
        mpllibs::error::do_impl<
          monad
          BOOST_PP_REPEAT(DO_MAX_ARGUMENT, DO_ARG, ~)
        >
      {};
    };
    
    #undef DO_ARG
  }
}

#endif

