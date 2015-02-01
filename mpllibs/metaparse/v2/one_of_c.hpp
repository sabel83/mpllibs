#ifndef MPLLIBS_METAPARSE_V2_ONE_OF_C_HPP
#define MPLLIBS_METAPARSE_V2_ONE_OF_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/one_of.hpp>
#include <mpllibs/metaparse/v2/lit_c.hpp>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <climits>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      #ifdef MPLLIBS_NO_SCALAR_VALUE
      #  error MPLLIBS_NO_SCALAR_VALUE already defined
      #endif
      #define MPLLIBS_NO_SCALAR_VALUE LONG_MAX

      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_ONE_OF_SIZE,
          long C,
          MPLLIBS_NO_SCALAR_VALUE
        )
      >
      struct one_of_c;

      #ifdef MPLLIBS_ONE_OF_C_LIT
      #  error MPLLIBS_ONE_OF_C_LIT already defined
      #endif
      #define MPLLIBS_ONE_OF_C_LIT(z, n, unused) lit_c<BOOST_PP_CAT(C, n)>

      #ifdef MPLLIBS_ONE_OF_C_CASE
      #  error MPLLIBS_ONE_OF_C_CASE already defined
      #endif
      #define MPLLIBS_ONE_OF_C_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, long C)> \
        struct \
          one_of_c< \
            BOOST_PP_ENUM_PARAMS(n, C) \
            BOOST_PP_COMMA_IF(n) \
            BOOST_PP_ENUM( \
              BOOST_PP_SUB(MPLLIBS_LIMIT_ONE_OF_SIZE, n), \
              MPLLIBS_NO_SCALAR_VALUE BOOST_PP_TUPLE_EAT(3), \
              ~ \
            ) \
          > : \
          one_of<BOOST_PP_ENUM(n, MPLLIBS_ONE_OF_C_LIT, ~)> \
        {};

      BOOST_PP_REPEAT(MPLLIBS_LIMIT_ONE_OF_SIZE, MPLLIBS_ONE_OF_C_CASE, ~)

      #undef MPLLIBS_ONE_OF_C_CASE
      #undef MPLLIBS_ONE_OF_C_LIT
      #undef MPLLIBS_NO_SCALAR_VALUE
    }
  }
}

#endif

