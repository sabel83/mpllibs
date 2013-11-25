#ifndef MPLLIBS_METAMONAD_V1_IMPL_LET_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/fwd/let_impl.hpp>
#include <mpllibs/metamonad/v1/impl/fwd/let_in_syntax.hpp>

#include <mpllibs/metamonad/limit_metafunction_arity.hpp>

#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/returns.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        // let_impl assumes, that let_impl<A, E1, A> is never instantiated
        template <class A, class E1, class E2>
        struct let_impl : returns<E2> {};

        #ifdef MPLLIBS_LET_CLASS
        #  error MPLLIBS_LET_CLASS alread defined
        #endif
        #define MPLLIBS_LET_CLASS(z, n, unused) \
          BOOST_PP_COMMA_IF(n) class
        
        #ifdef MPLLIBS_LET_REC_CASE
        #  error MPLLIBS_LET_REC_CASE alread defined
        #endif
        #define MPLLIBS_LET_REC_CASE(z, n, unused) \
          BOOST_PP_COMMA_IF(n) \
          typename let_in_syntax<A, E1, BOOST_PP_CAT(X, n)>::type

        #ifdef MPLLIBS_LET_TEMPLATE_CASE
        #  error MPLLIBS_LET_TEMPLATE_CASE already defined
        #endif
        #define MPLLIBS_LET_TEMPLATE_CASE(z, n, unused) \
          template < \
            class A, \
            class E1, \
            template<BOOST_PP_REPEAT(n, MPLLIBS_LET_CLASS, ~) > class T, \
            BOOST_PP_ENUM_PARAMS(n, class X) \
          > \
          struct let_impl<A, E1, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
            mpllibs::metamonad::v1::returns< \
              T<BOOST_PP_REPEAT(n, MPLLIBS_LET_REC_CASE, ~) > \
            > \
          {};
        
        BOOST_PP_REPEAT_FROM_TO(
          1,
          MPLLIBS_LIMIT_METAFUNCTION_ARITY,
          MPLLIBS_LET_TEMPLATE_CASE,
          ~
        )

        #undef MPLLIBS_LET_TEMPLATE_CASE
        #undef MPLLIBS_LET_CLASS
        #undef MPLLIBS_LET_REC_CASE

        template <class A, class E1, class E2>
        struct let_impl<A, E1, syntax<E2> > : syntax<E2> {};
      }
    }
  }
}

#endif

