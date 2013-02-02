#ifndef MPLLIBS_METAMONAD_MAKE_MONADIC_C_HPP
#define MPLLIBS_METAMONAD_MAKE_MONADIC_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/make_monadic.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/var.hpp>

#include <boost/mpl/apply.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/logical/and.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class MonadTag, class Expr>
    struct make_monadic;

    template <class MonadTag, class Expr>
    struct make_monadic_c : Expr {};

    #ifdef MPLLIBS_DEFINE_NAME
      #error MPLLIBS_DEFINE_NAME already defined
    #endif
    #define MPLLIBS_DEFINE_NAME(z, n, unused) \
      struct BOOST_PP_CAT(make_monadic__, n); \
      typedef \
        var<BOOST_PP_CAT(make_monadic__, n)> \
        BOOST_PP_CAT(make_monadic_, n);

    BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_DEFINE_NAME, ~)
    
    #undef MPLLBIS_DEFINE_NAME

    #ifdef MPLLIBS_MAKE_MONADIC_CASE_PRE
      #error MPLLIBS_MAKE_MONADIC_CASE_PRE already defined
    #endif
    #define MPLLIBS_MAKE_MONADIC_CASE_PRE(z, n, unused) \
      bind< \
        MonadTag, \
        make_monadic<MonadTag, syntax<BOOST_PP_CAT(T, n)> >, \
        lambda_c<BOOST_PP_CAT(make_monadic_, n),

    #ifdef MPLLIBS_MAKE_MONADIC_CASE_NA
      #error MPLLIBS_MAKE_MONADIC_CASE_NA
    #endif
    #define MPLLIBS_MAKE_MONADIC_CASE_NA(z, n, max) \
      template < \
        class MonadTag, \
        template <BOOST_PP_ENUM(max, class BOOST_PP_TUPLE_EAT(3), ~)> class T \
        BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, class T) \
      > \
      struct \
        make_monadic_c< \
          MonadTag, \
          T< \
            BOOST_PP_ENUM_PARAMS(n, T) \
            BOOST_PP_COMMA_IF(BOOST_PP_AND(n, BOOST_PP_SUB(max, n))) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(max, n), \
              boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        > : \
        BOOST_PP_REPEAT(n, MPLLIBS_MAKE_MONADIC_CASE_PRE, ~) \
          T< \
            BOOST_PP_ENUM_PARAMS(n, make_monadic_) \
            BOOST_PP_COMMA_IF(BOOST_PP_AND(n, BOOST_PP_SUB(max, n))) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(max, n), \
              boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > \
        BOOST_PP_REPEAT(n, > > BOOST_PP_TUPLE_EAT(3), ~) \
      {};

    #ifdef MPLLIBS_MAKE_MONADIC_CASE
      #error MPLLIBS_MAKE_MONADIC_CASE already defined
    #endif
    #define MPLLIBS_MAKE_MONADIC_CASE(z, n, unused) \
      BOOST_PP_REPEAT(BOOST_PP_INC(n), MPLLIBS_MAKE_MONADIC_CASE_NA, n)

    BOOST_PP_REPEAT_FROM_TO(
      1,
      BOOST_PP_INC(BOOST_MPL_LIMIT_METAFUNCTION_ARITY),
      MPLLIBS_MAKE_MONADIC_CASE,
      ~
    )

    #undef MPLLIBS_MAKE_MONADIC_CASE
    #undef MPLLIBS_MAKE_MONADIC_CASE_PRE
    #undef MPLLIBS_MAKE_MONADIC_CASE_NA
  }
}

#endif

