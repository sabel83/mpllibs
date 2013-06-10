#ifndef MPLLIBS_METAPARSE_IMPL_CONCAT_HPP
#define MPLLIBS_METAPARSE_IMPL_CONCAT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/string_fwd.hpp>

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/arithmetic/mul.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class A, class B>
      struct concat;

#ifdef MPLLIBS_VARIADIC_STRING
      template <char... As, char... Bs>
      struct concat<string<As...>, string<Bs...>> : string<As..., Bs...> {};
#else
      template <class A, class B>
      struct concat_impl;

      #ifdef MPLLIBS_ARG
        #error MPLLIBS_ARG already defined
      #endif
      #define MPLLIBS_ARG(z, n, unused) BOOST_PP_CAT(B, BOOST_PP_INC(n))

      #ifdef MPLLIBS_CONCAT
        #error MPLLIBS_CONCAT already defined
      #endif
      #define MPLLIBS_CONCAT(z, n, unused) \
        template < \
          BOOST_PP_ENUM_PARAMS(n, int A) BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int B) \
        > \
        struct \
          concat_impl< \
            string< \
              BOOST_PP_ENUM_PARAMS(n, A) \
              BOOST_PP_COMMA_IF( \
                BOOST_PP_MUL(BOOST_PP_SUB(MPLLIBS_STRING_MAX_LENGTH, n), n) \
              ) \
              BOOST_PP_ENUM( \
                BOOST_PP_SUB(MPLLIBS_STRING_MAX_LENGTH, n), \
                MPLLIBS_NO_CHAR BOOST_PP_TUPLE_EAT(3), \
                ~ \
              ) \
            >, \
            string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, B)> \
          > : \
          concat< \
            string<BOOST_PP_ENUM_PARAMS(n, A) BOOST_PP_COMMA_IF(n) B0>, \
            string< \
              BOOST_PP_ENUM( \
                BOOST_PP_DEC(MPLLIBS_STRING_MAX_LENGTH), \
                MPLLIBS_ARG, \
                ~ \
              ) \
            > \
          > \
        {};

      BOOST_PP_REPEAT(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_CONCAT, ~)

      #undef MPLLIBS_ARG
      #undef MPLLIBS_CONCAT

      template <class S>
      struct concat<S, string<> > : S {};

      template <class A, class B>
      struct concat : concat_impl<A, B> {};
#endif
    }
  }
}

#endif

