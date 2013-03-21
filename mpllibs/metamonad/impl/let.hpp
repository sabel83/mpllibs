#ifndef MPLLIBS_METAMONAD_IMPL_LET_HPP
#define MPLLIBS_METAMONAD_IMPL_LET_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/find_if.hpp>

#include <boost/type_traits.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      template <class A, class E1, class E2>
      struct let_impl;

      template <class A, class E1, class E2>
      struct let_in_syntax : let_impl<A, E1, E2> {};

      template <class A, class E1, class E2>
      struct let_in_syntax<A, E1, syntax<E2> > : syntax<E2> {};

      template <class A, class E1>
      struct let_in_syntax<A, E1, A> : returns<E1> {};

      // let_impl assumes, that let_impl<A, E1, A> is never instantiated
      template <class A, class E1, class E2>
      struct let_impl : returns<E2> {};

      #ifndef MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT
        #define MPLLIBS_LET_MAX_TEMPLATE_ARGUMENT 21
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
        BOOST_PP_COMMA_IF(n) \
        typename let_in_syntax<A, E1, BOOST_PP_CAT(X, n)>::type

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
        struct let_impl<A, E1, T<BOOST_PP_ENUM_PARAMS(n, X)> > : \
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
}

#endif

