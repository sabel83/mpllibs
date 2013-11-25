#ifndef MPLLIBS_SAFE_PRINTF_V1_FWD_PRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_V1_FWD_PRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/printf_max_argument.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#include <cstdio>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace v1
    {
      #ifdef MPLLIBS_PRINTF_TEMPLATE
      #  error MPLLIBS_PRINTF_TEMPLATE already defined
      #endif
      #define MPLLIBS_PRINTF_TEMPLATE(n) \
        template < \
          class FormatString \
          BOOST_PP_COMMA_IF(n) BOOST_PP_ENUM_PARAMS(n, class T) \
        >
 
      #ifdef MPLLIBS_PRINTF
      #  error MPLLIBS_PRINTF already defined
      #endif
      #define MPLLIBS_PRINTF(z, n, unused) \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int printf(BOOST_PP_ENUM_BINARY_PARAMS(n, T, t)); \
        \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int fprintf( \
          FILE* stream BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        ); \
        \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int sprintf( \
          char* s BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        );
  
      BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_PRINTF, ~)
  
      #undef MPLLIBS_PRINTF
      #undef MPLLIBS_PRINTF_TEMPLATE
    }
  }
}

#endif

