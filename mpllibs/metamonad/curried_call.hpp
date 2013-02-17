#ifndef MPLLIBS_METAMONAD_CURRIED_CALL_HPP
#define MPLLIBS_METAMONAD_CURRIED_CALL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/var.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      #ifdef MPLLIBS_CURRY_VAR
        #error MPLLIBS_CURRY_VAR already defined
      #endif
      #define MPLLIBS_CURRY_VAR(z, n, unused) \
        struct BOOST_PP_CAT(curry_var__, n); \
        typedef var<BOOST_PP_CAT(curry_var__, n)> BOOST_PP_CAT(curry_var_, n);

      BOOST_PP_REPEAT(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, MPLLIBS_CURRY_VAR, ~)

      #undef MPLLIBS_CURRY_VAR
    }

    #ifdef MPLLIBS_CURRIED_CALL_CASE
      #error MPLLIBS_CURRIED_CALL_CASE already defined
    #endif
    // k < n, since the k == n case is the general case
    #define MPLLIBS_CURRIED_CALL_SUBCASE(z, k, n) \
      template < \
        template <BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~)> class F \
        BOOST_PP_COMMA_IF(k) BOOST_PP_ENUM_PARAMS(k, class T) \
      > \
      struct \
        BOOST_PP_CAT(curried_call, n)< \
          F, \
          BOOST_PP_ENUM_PARAMS(k, T) BOOST_PP_COMMA_IF(k) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(n, k), \
            boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : \
          lambda_c< \
            BOOST_PP_ENUM_PARAMS(BOOST_PP_SUB(n, k), impl::curry_var_) \
            BOOST_PP_COMMA_IF(BOOST_PP_SUB(n, k)) \
            F< \
              BOOST_PP_ENUM_PARAMS(k, T) BOOST_PP_COMMA_IF(k) \
              BOOST_PP_ENUM_PARAMS(BOOST_PP_SUB(n, k), impl::curry_var_) \
            > \
          > \
        {};

    #ifdef MPLLIBS_CURRIED_CALL_CASE
      #error MPLLIBS_CURRIED_CALL_CASE already defined
    #endif
    #define MPLLIBS_CURRIED_CALL_CASE(z, n, unused) \
      template < \
        template <BOOST_PP_ENUM(n, class BOOST_PP_TUPLE_EAT(3), ~)> class F, \
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(n, class T, boost::mpl::na) \
      > \
      struct BOOST_PP_CAT(curried_call, n) : F<BOOST_PP_ENUM_PARAMS(n, T)> {}; \
      \
      BOOST_PP_REPEAT(n, MPLLIBS_CURRIED_CALL_SUBCASE, n)

    BOOST_PP_REPEAT_FROM_TO(
      1,
      BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
      MPLLIBS_CURRIED_CALL_CASE,
      ~
    )

    #undef MPLLIBS_CURRIED_CALL_CASE
    #undef MPLLIBS_CURRIED_CALL_SUBCASE
  }
}

#endif

