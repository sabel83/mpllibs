#ifndef MPLLIBS_SAFE_PRINTF_V1_PRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_V1_PRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/fwd/printf.hpp>
#include <mpllibs/safe_printf/v1/valid_arguments.hpp>

#include <boost/mpl/string.hpp>
#include <boost/mpl/vector.hpp>

#include <boost/static_assert.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
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
  
      #ifdef MPLLIBS_PRINTF_BOX
      #  error MPLLIBS_PRINTF_BOX already defined
      #endif
      #define MPLLIBS_PRINTF_BOX(z, n, unused) \
        metamonad::box<BOOST_PP_CAT(T, n)>
  
      #ifdef MPLLIBS_PRINTF_ASSERT
      #  error MPLLIBS_PRINTF_ASSERT already defined
      #endif
      #define MPLLIBS_PRINTF_ASSERT(n) \
        BOOST_STATIC_ASSERT(( \
          valid_arguments< \
            FormatString, \
            boost::mpl::vector<BOOST_PP_ENUM(n, MPLLIBS_PRINTF_BOX, ~)> \
          >::type::value \
        )) \
  
      #ifdef MPLLIBS_PRINTF_ARGS
      #  error MPLLIBS_PRINTF_ARGS already defined
      #endif
      #define MPLLIBS_PRINTF_ARGS(n) \
        boost::mpl::c_str<FormatString>::type::value BOOST_PP_COMMA_IF(n) \
        BOOST_PP_ENUM_PARAMS(n, t) \
      
      #ifdef MPLLIBS_PRINTF
      #  error MPLLIBS_PRINTF already defined
      #endif
      #define MPLLIBS_PRINTF(z, n, unused) \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int printf(BOOST_PP_ENUM_BINARY_PARAMS(n, T, t)) \
        { \
          MPLLIBS_PRINTF_ASSERT(n); \
          return ::printf(MPLLIBS_PRINTF_ARGS(n)); \
        } \
        \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int fprintf( \
          FILE* stream BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        ) \
        { \
          MPLLIBS_PRINTF_ASSERT(n); \
          return ::fprintf(stream, MPLLIBS_PRINTF_ARGS(n)); \
        } \
        \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int sprintf( \
          char* s BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        ) \
        { \
          MPLLIBS_PRINTF_ASSERT(n); \
          return ::sprintf(s, MPLLIBS_PRINTF_ARGS(n)); \
        } \
        \
        MPLLIBS_PRINTF_TEMPLATE(n) \
        int snprintf( \
          char* s, size_t size BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_BINARY_PARAMS(n, T, t) \
        ) \
        { \
          MPLLIBS_PRINTF_ASSERT(n); \
          return ::snprintf(s, size, MPLLIBS_PRINTF_ARGS(n)); \
        }
  
      #ifdef _MSC_VER
      #  pragma warning(push)
      #  pragma warning(disable: 4996)
      #endif
  
      BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_PRINTF, ~)
  
      #ifdef _MSC_VER
      #  pragma warning(pop)
      #endif
      
      #undef MPLLIBS_PRINTF
      #undef MPLLIBS_PRINTF_BOX
      #undef MPLLIBS_PRINTF_ARGS
      #undef MPLLIBS_PRINTF_ASSERT
      #undef MPLLIBS_PRINTF_TEMPLATE
    }
  }
}

#endif

