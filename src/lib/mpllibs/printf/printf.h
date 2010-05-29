#ifndef MPLLIBS_PRINTF_PRINTF_H
#define MPLLIBS_PRINTF_PRINTF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/printf/VerifyPrintfArguments.h>

#include <boost/mpl/string.hpp>
#include <boost/mpl/list.hpp>

#include <boost/static_assert.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>

#include <cstdio>

namespace mpllibs
{
  namespace printf
  {
    #ifndef PRINTF_MAX_ARGUMENT
      #define PRINTF_MAX_ARGUMENT 10
    #endif
    
    #ifdef PRINTF_NO_CLASS_ARGS
      #error PRINTF_NO_CLASS_ARGS already defined
    #endif
    #define PRINTF_NO_CLASS_ARGS(z, n, unused) \
      , t##n
    
    #ifdef PRINTF_CLASS_ARGS
      #error PRINTF_CLASS_ARGS already defined
    #endif
    #define PRINTF_CLASS_ARGS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) T##n

    #ifdef PRINTF_ARGS
      #error PRINTF_ARGS already defined
    #endif
    #define PRINTF_ARGS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) T##n t##n

    #ifdef PRINTF_CLASSES
      #error PRINTF_CLASSES already defined
    #endif
    #define PRINTF_CLASSES(z, n, unused) \
      , class T##n

    #ifdef PRINTF
      #error PRINTF already defined
    #endif
    #define PRINTF(z, n, unused) \
      template <class formatString BOOST_PP_REPEAT(n, PRINTF_CLASSES, ~)> \
      int printf(BOOST_PP_REPEAT(n, PRINTF_ARGS, ~)) \
      { \
        BOOST_STATIC_ASSERT(( \
          mpllibs::printf::VerifyPrintfArguments< \
            formatString, \
            boost::mpl::list<BOOST_PP_REPEAT(n, PRINTF_CLASS_ARGS, ~)> \
          >::type::value \
        )); \
        return ::printf( \
          boost::mpl::c_str<formatString>::type::value \
          BOOST_PP_REPEAT(n, PRINTF_NO_CLASS_ARGS, ~) \
        ); \
      }
    
    #ifdef FPRINTF
      #error FPRINTF already defined
    #endif
    #define FPRINTF(z, n, unused) \
      template <class formatString BOOST_PP_REPEAT(n, PRINTF_CLASSES, ~)> \
      int fprintf(FILE* stream BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT(n, PRINTF_ARGS, ~)) \
      { \
        BOOST_STATIC_ASSERT(( \
          mpllibs::printf::VerifyPrintfArguments< \
            formatString, \
            boost::mpl::list<BOOST_PP_REPEAT(n, PRINTF_CLASS_ARGS, ~)> \
          >::type::value \
        )); \
        return ::fprintf( \
          stream, \
          boost::mpl::c_str<formatString>::type::value \
          BOOST_PP_REPEAT(n, PRINTF_NO_CLASS_ARGS, ~) \
        ); \
      }

    #ifdef SPRINTF
      #error SPRINTF already defined
    #endif
    #define SPRINTF(z, n, unused) \
      template <class formatString BOOST_PP_REPEAT(n, PRINTF_CLASSES, ~)> \
      int sprintf(char* s BOOST_PP_COMMA_IF(n) BOOST_PP_REPEAT(n, PRINTF_ARGS, ~)) \
      { \
        BOOST_STATIC_ASSERT(( \
          mpllibs::printf::VerifyPrintfArguments< \
            formatString, \
            boost::mpl::list<BOOST_PP_REPEAT(n, PRINTF_CLASS_ARGS, ~)> \
          >::type::value \
        )); \
        return ::sprintf( \
          s, \
          boost::mpl::c_str<formatString>::type::value \
          BOOST_PP_REPEAT(n, PRINTF_NO_CLASS_ARGS, ~) \
        ); \
      }
    
    BOOST_PP_REPEAT(PRINTF_MAX_ARGUMENT, PRINTF, ~)
    BOOST_PP_REPEAT(PRINTF_MAX_ARGUMENT, FPRINTF, ~)
    BOOST_PP_REPEAT(PRINTF_MAX_ARGUMENT, SPRINTF, ~)
    
    #undef PRINTF
    #undef FPRINTF
    #undef SPRINTF
    
    #undef PRINTF_CLASSES
    #undef PRINTF_ARGS
    #undef PRINTF_CLASS_ARGS
    #undef PRINTF_NO_CLASS_ARGS
  }
}

#endif

