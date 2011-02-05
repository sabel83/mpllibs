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
    template <class a, class e1, class e2>
    struct let_impl;

    template <class a, class e1, class e2>
    struct let : let_impl<a, e1, e2> {};

    template <class a, class e1>
    struct let<a, e1, a> : mpllibs::error::util::id<e1> {};

    
    // let_impl assumes, that let_impl<a, e1, a> is never instantiated
    template <class a, class e1, class e2>
    struct let_impl : mpllibs::error::util::id<e2> {};

    template <class a, class e1a, class e1b, class e2>
    struct let_impl<a, e1a, let<a, e1b, e2> > :
      mpllibs::error::util::id<let<a, e1b, e2> >
    {};

    template <class a, class e1, class e2>
    struct letrec;

    template <class a, class e1a, class e1b, class e2>
    struct let_impl<a, e1a, letrec<a, e1b, e2> > :
      mpllibs::error::util::id<letrec<a, e1b, e2> >
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
      BOOST_PP_COMMA_IF(n) typename mpllibs::error::let<a, e1, x##n>::type

    #ifdef LET_TEMPLATE_CASE
      #error LET_TEMPLATE_CASE already defined
    #endif
    #define LET_TEMPLATE_CASE(z, n, unused) \
      template < \
        class a, \
        class e1, \
        template<BOOST_PP_REPEAT(n, LET_CLASS, ~) > class t, \
        BOOST_PP_ENUM_PARAMS(n, class x) \
      > \
      struct let_impl<a, e1, t<BOOST_PP_ENUM_PARAMS(n, x)> > : \
        mpllibs::error::util::id< t< BOOST_PP_REPEAT(n, LET_REC_CASE, ~) > > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(1, LET_MAX_TEMPLATE_ARGUMENT, LET_TEMPLATE_CASE, ~)

    #undef LET_TEMPLATE_CASE
    #undef LET_CLASS
    #undef LET_REC_CASE
  }
}

#endif

