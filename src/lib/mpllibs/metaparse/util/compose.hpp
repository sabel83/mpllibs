#ifndef MPLLIBS_UTIL_COMPOSE_H
#define MPLLIBS_UTIL_COMPOSE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      #ifndef COMPOSE_MAX_ARGUMENT
        #define COMPOSE_MAX_ARGUMENT 10
      #endif
      
      #ifndef COMPOSE_MAX_INIT_ARGUMENT
        #define COMPOSE_MAX_INIT_ARGUMENT 3
      #endif
      
      #if COMPOSE_MAX_INIT_ARGUMENT >= BOOST_MPL_LIMIT_METAFUNCTION_ARITY
        #error COMPOSE_MAX_INIT_ARGUMENT >= BOOST_MPL_LIMIT_METAFUNCTION_ARITY
      #endif
      
      #ifdef REPEAT_CONSTANT
        #error REPEAT_CONSTANT already defined
      #endif
      #define REPEAT_CONSTANT(z, n, constant) constant
      
      #ifdef COMPOSE
        #error COMPOSE already defined
      #endif
      #define COMPOSE(z, n, unused) \
        template < \
          BOOST_PP_ENUM_PARAMS(n, class F) \
          BOOST_PP_COMMA_IF(n) class Mock = int \
        > \
        struct compose##n \
        { \
          template < \
            BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT( \
              COMPOSE_MAX_INIT_ARGUMENT, \
              class A, \
              boost::mpl::na \
            ) \
          > \
          struct apply \
          { \
            typedef \
              BOOST_PP_ENUM_PARAMS(n, typename boost::mpl::apply<F) \
                BOOST_PP_COMMA_IF(n) \
                BOOST_PP_ENUM_PARAMS(COMPOSE_MAX_INIT_ARGUMENT, A) \
              BOOST_PP_REPEAT(n, REPEAT_CONSTANT, >::type) \
              type; \
          }; \
        };
    
      BOOST_PP_REPEAT_FROM_TO(1, COMPOSE_MAX_ARGUMENT, COMPOSE, ~)
    
      #undef COMPOSE
    


      struct unused_composed_argument;
    
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          COMPOSE_MAX_ARGUMENT,
          class F,
          unused_composed_argument
        ),
        class Mock = int
      >
      struct compose;
      
      #ifdef COMPOSE_UNUSED_PARAM
        #error COMPOSE_UNUSED_PARAM already defined
      #endif
      #define COMPOSE_UNUSED_PARAM(z, n, unused) \
        BOOST_PP_COMMA_IF(n) unused_composed_argument

      template <>
      struct compose<
        BOOST_PP_REPEAT(COMPOSE_MAX_ARGUMENT, COMPOSE_UNUSED_PARAM, ~),
        int
      >
      {
        template <class T>
        struct apply
        {
          typedef T type;
        };
      };
    
      #ifdef COMPOSE_CASE
        #error COMPOSE_CASE already defined
      #endif
      #define COMPOSE_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class F)> \
        struct compose< \
          BOOST_PP_ENUM_PARAMS(n, F) \
          BOOST_PP_COMMA_IF(n) \
          BOOST_PP_REPEAT( \
            BOOST_PP_SUB(COMPOSE_MAX_ARGUMENT, n), \
            COMPOSE_UNUSED_PARAM, \
            ~ \
          ) \
          BOOST_PP_COMMA_IF(BOOST_PP_SUB(COMPOSE_MAX_ARGUMENT, n)) \
          int \
        > : \
          mpllibs::metaparse::util::compose##n<BOOST_PP_ENUM_PARAMS(n, F)> \
        {};
    
      BOOST_PP_REPEAT_FROM_TO(1, COMPOSE_MAX_ARGUMENT, COMPOSE_CASE, ~)
    
      #undef COMPOSE_CASE
      #undef COMPOSE_UNUSED_PARAM
    
      #undef REPEAT_CONSTANT
    }
  }
}

#endif

