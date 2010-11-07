#ifndef MPLLIBS_PARSER_ANY_ONE_OF1_H
#define MPLLIBS_PARSER_ANY_ONE_OF1_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_of.h>
#include <mpllibs/metaparse/any1.h>

#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        PARSER_ONE_OF_MAX_ARGUMENT,
        class p,
        mpllibs::metaparse::unused_one_of_argument
      ),
      class mock = int
    >
    struct any_one_of1;
    
    #ifdef PARSER_ANY_ONE_OF1_UNUSED_PARAM
      #error PARSER_ANY_ONE_OF1_UNUSED_PARAM already defined
    #endif
    #define PARSER_ANY_ONE_OF1_UNUSED_PARAM(z, n, unused) \
      BOOST_PP_COMMA_IF(n) mpllibs::metaparse::unused_one_of_argument
    
    #ifdef PARSER_ANY_ONE_OF1_CASE
      #error PARSER_ANY_ONE_OF1_CASE already defined
    #endif
    #define PARSER_ANY_ONE_OF1_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, class p)> \
      struct any_one_of1< \
        BOOST_PP_ENUM_PARAMS(n, p) \
        BOOST_PP_COMMA_IF(n) \
        BOOST_PP_REPEAT( \
          BOOST_PP_SUB(PARSER_ONE_OF_MAX_ARGUMENT, n), \
          PARSER_ANY_ONE_OF1_UNUSED_PARAM, \
          ~ \
        ) \
      > : \
        mpllibs::metaparse::any1< \
          mpllibs::metaparse::one_of_##n<BOOST_PP_ENUM_PARAMS(n, p)> \
        > \
      {};
    
    BOOST_PP_REPEAT(PARSER_ONE_OF_MAX_ARGUMENT, PARSER_ANY_ONE_OF1_CASE, ~)
    
    #undef PARSER_ANY_ONE_OF1_CASE
    #undef PARSER_ANY_ONE_OF1_UNUSED_PARAM
  }
}

#endif

