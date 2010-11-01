#ifndef MPLLIBS_PARSER_LAST_OF_H
#define MPLLIBS_PARSER_LAST_OF_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.h>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        SEQUENCE_MAX_ARGUMENT,
        class p,
        mpllibs::metaparse::impl::sequence_no_argument
      )
    >
    struct last_of;


    #ifdef SEQUENCE_UNUSED_PARAM
      #error SEQUENCE_UNUSED_PARAM already defined
    #endif
    #define SEQUENCE_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) mpllibs::metaparse::impl::sequence_no_argument
    
    #ifdef LAST_OF_N
      #error LAST_OF_N already defined
    #endif
    #define LAST_OF_N(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class p)> \
      struct last_of< \
        BOOST_PP_ENUM_PARAMS(n, p) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(SEQUENCE_MAX_ARGUMENT, n), \
          SEQUENCE_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        mpllibs::metaparse::nth_of_c##n< \
          n - 1 BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM_PARAMS(n, p) \
        > \
      {};
    
    BOOST_PP_REPEAT(SEQUENCE_MAX_ARGUMENT, LAST_OF_N, ~)
    
    #undef LAST_OF_N
    #undef SEQUENCE_UNUSED_PARAM
  }
}

#endif

