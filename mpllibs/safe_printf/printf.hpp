#ifndef MPLLIBS_SAFE_PRINTF_PRINTF_HPP
#define MPLLIBS_SAFE_PRINTF_PRINTF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/verify_printf_arguments.hpp>

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
  namespace safe_printf
  {
    #ifndef MPLLIBS_PRINTF_MAX_ARGUMENT
      #define MPLLIBS_PRINTF_MAX_ARGUMENT 10
    #endif
    
    #ifdef MPLLIBS_PRINTF_NO_CLASS_ARGS
      #error MPLLIBS_PRINTF_NO_CLASS_ARGS already defined
    #endif
    #define MPLLIBS_PRINTF_NO_CLASS_ARGS(z, n, unused) \
      , t##n
    
    #ifdef MPLLIBS_PRINTF_CLASS_ARGS
      #error MPLLIBS_PRINTF_CLASS_ARGS already defined
    #endif
    #define MPLLIBS_PRINTF_CLASS_ARGS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) T##n

    #ifdef MPLLIBS_PRINTF_ARGS
      #error MPLLIBS_PRINTF_ARGS already defined
    #endif
    #define MPLLIBS_PRINTF_ARGS(z, n, unused) \
      BOOST_PP_COMMA_IF(n) T##n t##n

    #ifdef MPLLIBS_PRINTF_CLASSES
      #error MPLLIBS_PRINTF_CLASSES already defined
    #endif
    #define MPLLIBS_PRINTF_CLASSES(z, n, unused) \
      , class T##n

    #ifdef MPLLIBS_PRINTF
      #error MPLLIBS_PRINTF already defined
    #endif
    #define MPLLIBS_PRINTF(z, n, unused) \
      template < \
        class FormatString BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_CLASSES, ~) \
      > \
      int printf(BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_ARGS, ~)) \
      { \
        BOOST_STATIC_ASSERT(( \
          verify_printf_arguments< \
            FormatString, \
            boost::mpl::list<BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_CLASS_ARGS, ~)> \
          >::type::value \
        )); \
        return ::printf( \
          boost::mpl::c_str<FormatString>::type::value \
          BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_NO_CLASS_ARGS, ~) \
        ); \
      }
    
    #ifdef MPLLIBS_FPRINTF
      #error MPLLIBS_FPRINTF already defined
    #endif
    #define MPLLIBS_FPRINTF(z, n, unused) \
      template < \
        class FormatString BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_CLASSES, ~) \
      > \
      int fprintf( \
        FILE* stream BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_ARGS, ~) \
      ) \
      { \
        BOOST_STATIC_ASSERT(( \
          verify_printf_arguments< \
            FormatString, \
            boost::mpl::list<BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_CLASS_ARGS, ~)> \
          >::type::value \
        )); \
        return ::fprintf( \
          stream, \
          boost::mpl::c_str<FormatString>::type::value \
          BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_NO_CLASS_ARGS, ~) \
        ); \
      }

    #ifdef MPLLIBS_SPRINTF
      #error MPLLIBS_SPRINTF already defined
    #endif
    #define MPLLIBS_SPRINTF(z, n, unused) \
      template < \
        class FormatString BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_CLASSES, ~) \
      > \
      int sprintf( \
        char* s BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_ARGS, ~) \
      ) \
      { \
        BOOST_STATIC_ASSERT(( \
          verify_printf_arguments< \
            FormatString, \
            boost::mpl::list<BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_CLASS_ARGS, ~)> \
          >::type::value \
        )); \
        return ::sprintf( \
          s, \
          boost::mpl::c_str<FormatString>::type::value \
          BOOST_PP_REPEAT(n, MPLLIBS_PRINTF_NO_CLASS_ARGS, ~) \
        ); \
      }
    
    BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_PRINTF, ~)
    BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_FPRINTF, ~)
    BOOST_PP_REPEAT(MPLLIBS_PRINTF_MAX_ARGUMENT, MPLLIBS_SPRINTF, ~)
    
    #undef MPLLIBS_PRINTF
    #undef MPLLIBS_FPRINTF
    #undef MPLLIBS_SPRINTF
    
    #undef MPLLIBS_PRINTF_CLASSES
    #undef MPLLIBS_PRINTF_ARGS
    #undef MPLLIBS_PRINTF_CLASS_ARGS
    #undef MPLLIBS_PRINTF_NO_CLASS_ARGS
  }
}

#endif

