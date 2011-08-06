#ifndef MPLLIBS_METAMONAD_TRY_HPP
#define MPLLIBS_METAMONAD_TRY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/util/id.hpp>

#include <mpllibs/metamonad/do_try.hpp>
#include <mpllibs/metamonad/do_.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    #ifdef MPLLIBS_DEFINE_NAME
      #error MPLLIBS_DEFINE_NAME already defined
    #endif
    #define MPLLIBS_DEFINE_NAME(z, n, unused) \
      struct t##n;

    BOOST_PP_REPEAT(MPLLIBS_DO_MAX_ARGUMENT, MPLLIBS_DEFINE_NAME, ~)
    
    #undef MPLLBIS_DEFINE_NAME
  
    template <class F>
    struct try_ : do_try<F> {};
    
    #ifdef MPLLIBS_CLASS
      #error MPLLIBS_CLASS already defined
    #endif
    #define MPLLIBS_CLASS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) class
    
    #ifdef MPLLIBS_SET_T
      #error MPLLIBS_SET_T already defined
    #endif
    #define MPLLIBS_SET_T(z, n, unused) \
      BOOST_PP_COMMA_IF(n) MPLLIBS_SET<t##n, T##n>
    
    #ifdef MPLLIBS_TRY_CASE
      #error MPLLIBS_TRY_CASE already defined
    #endif
    #define MPLLIBS_TRY_CASE(z, n, unused) \
      template <  \
        template <BOOST_PP_REPEAT(n, MPLLIBS_CLASS, ~)> class F, \
        BOOST_PP_ENUM_PARAMS(n, class T) \
      > \
      struct try_<F<BOOST_PP_ENUM_PARAMS(n, T)> > : \
        do_try< \
          BOOST_PP_REPEAT(n, MPLLIBS_SET_T, ~) \
          BOOST_PP_COMMA_IF(n) \
          F<BOOST_PP_ENUM_PARAMS(n, t)> \
        > \
      {};
    
    BOOST_PP_REPEAT_FROM_TO(
      1,
      BOOST_PP_SUB(MPLLIBS_DO_MAX_ARGUMENT, 1),
      MPLLIBS_TRY_CASE,
      ~
    )
    
    #undef MPLLIBS_SET_T
    #undef MPLLIBS_TRY_CASE
    #undef MPLLIBS_CLASS
  }
}

#endif

