#ifndef MPLLIBS_ERROR_LET_H
#define MPLLIBS_ERROR_LET_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/util/id.h>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class A, class E1, class E2>
    struct let_impl;

    template <class A, class E1, class E2>
    struct let : let_impl<A, E1, E2> {};

    template <class A, class E1>
    struct let<A, E1, A> : mpllibs::error::util::id<E1> {};

    
    // let_impl assumes, that let_impl<A, E1, A> is never instantiated
    template <class A, class E1, class E2>
    struct let_impl : mpllibs::error::util::id<E2> {};

    template <class A, class E1a, class E1b, class E2>
    struct let_impl<A, E1a, let<A, E1b, E2> > :
      mpllibs::error::util::id<let<A, E1b, E2> >
    {};

    template <class A, class E1, class E2>
    struct letrec;

    template <class A, class E1a, class E1b, class E2>
    struct let_impl<A, E1a, letrec<A, E1b, E2> > :
      mpllibs::error::util::id<letrec<A, E1b, E2> >
    {};

    #ifndef LET_MAX_TEMPLATE_ARGUMENT
      #define LET_MAX_TEMPLATE_ARGUMENT 10
    #endif
    
    #ifdef LET_CLASS
      #error LET_CLASS alread defined
    #endif
    #define LET_CLASS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) class
    
    #ifdef LET_REC_CASE
      #error LET_REC_CASE alread defined
    #endif
    #define LET_REC_CASE(z, n, unused) \
      BOOST_PP_COMMA_IF(n) typename let<A, E1, X##n>::type

    #ifdef LET_TEMPLATE_CASE
      #error LET_TEMPLATE_CASE already defined
    #endif
    #define LET_TEMPLATE_CASE(z, n, unused) \
      template < \
        class A, \
        class E1, \
        template<BOOST_PP_REPEAT(n, LET_CLASS, ~) > class T, \
        BOOST_PP_ENUM_PARAMS(n, class X) \
      > \
      struct let_impl<A, E1, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
        mpllibs::error::util::id< T< BOOST_PP_REPEAT(n, LET_REC_CASE, ~) > > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(1, LET_MAX_TEMPLATE_ARGUMENT, LET_TEMPLATE_CASE, ~)

    #undef LET_TEMPLATE_CASE
    #undef LET_CLASS
    #undef LET_REC_CASE
  }
}

#endif

