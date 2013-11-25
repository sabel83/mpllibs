#ifndef MPLLIBS_METAPARSE_V1_ONE_CHAR_EXCEPT_HPP
#define MPLLIBS_METAPARSE_V1_ONE_CHAR_EXCEPT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/error/unexpected_character.hpp>
#include <mpllibs/metaparse/v1/impl/is_any.hpp>
#include <mpllibs/metaparse/v1/impl/one_char_except_not_used.hpp>
#include <mpllibs/metaparse/v1/one_char.hpp>
#include <mpllibs/metaparse/v1/accept_when.hpp>
#include <mpllibs/metaparse/v1/define_error.hpp>
#include <mpllibs/metaparse/limit_one_char_except_size.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/arithmetic/mul.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_ONE_CHAR_EXCEPT_SIZE,
          class C,
          impl::one_char_except_not_used
        )
      >
      struct one_char_except;

      #ifdef MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE
      #  error MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE already defined
      #endif
      #define MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class T)> \
        struct one_char_except< \
          BOOST_PP_ENUM_PARAMS(n, T) \
          BOOST_PP_COMMA_IF( \
            BOOST_PP_MUL( \
              n, \
              BOOST_PP_SUB(BOOST_PP_DEC(MPLLIBS_LIMIT_ONE_CHAR_EXCEPT_SIZE), n)\
            ) \
          ) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(BOOST_PP_DEC(MPLLIBS_LIMIT_ONE_CHAR_EXCEPT_SIZE), n), \
            impl::one_char_except_not_used BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > :\
          accept_when< \
            one_char, \
            impl::BOOST_PP_CAT(is_any, n)<BOOST_PP_ENUM_PARAMS(n, T)>, \
            error::unexpected_character \
          > \
        {};

      BOOST_PP_REPEAT(
        MPLLIBS_LIMIT_ONE_CHAR_EXCEPT_SIZE,
        MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE,
        ~
      )

      #undef MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE
    }
  }
}

#endif

