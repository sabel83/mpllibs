#ifndef MPLLIBS_METAPARSE_UTIL_COMPOSE_HPP
#define MPLLIBS_METAPARSE_UTIL_COMPOSE_HPP

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
      #ifndef MPLLIBS_COMPOSE_MAX_ARGUMENT
        #define MPLLIBS_COMPOSE_MAX_ARGUMENT 10
      #endif
      
      #ifndef MPLLIBS_COMPOSE_MAX_INIT_ARGUMENT
        #define MPLLIBS_COMPOSE_MAX_INIT_ARGUMENT 3
      #endif
      
      #if MPLLIBS_COMPOSE_MAX_INIT_ARGUMENT >= BOOST_MPL_LIMIT_METAFUNCTION_ARITY
        #error MPLLIBS_COMPOSE_MAX_INIT_ARGUMENT >= BOOST_MPL_LIMIT_METAFUNCTION_ARITY
      #endif
      
      #ifdef MPLLIBS_REPEAT_CONSTANT
        #error MPLLIBS_REPEAT_CONSTANT already defined
      #endif
      #define MPLLIBS_REPEAT_CONSTANT(z, n, constant) constant
      
      #ifdef MPLLIBS_COMPOSE
        #error MPLLIBS_COMPOSE already defined
      #endif
      #define MPLLIBS_COMPOSE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class F)> \
        struct compose##n \
        { \
          typedef compose##n type; \
          \
          template < \
            BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT( \
              MPLLIBS_COMPOSE_MAX_INIT_ARGUMENT, \
              class A, \
              boost::mpl::na \
            ) \
          > \
          struct apply \
          { \
            typedef \
              BOOST_PP_ENUM_PARAMS(n, typename boost::mpl::apply<F) \
                BOOST_PP_COMMA_IF(n) \
                BOOST_PP_ENUM_PARAMS(MPLLIBS_COMPOSE_MAX_INIT_ARGUMENT, A) \
              BOOST_PP_REPEAT(n, MPLLIBS_REPEAT_CONSTANT, >::type) \
              type; \
          }; \
        };
    
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_COMPOSE_MAX_ARGUMENT,
        MPLLIBS_COMPOSE,
        ~
      )
    
      #undef MPLLIBS_COMPOSE
    


      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_COMPOSE_MAX_ARGUMENT,
          class F,
          boost::mpl::na
        )
      >
      struct compose;
      
      #ifdef MPLLIBS_COMPOSE_UNUSED_PARAM
        #error MPLLIBS_COMPOSE_UNUSED_PARAM already defined
      #endif
      #define MPLLIBS_COMPOSE_UNUSED_PARAM(z, n, unused) \
        BOOST_PP_COMMA_IF(n) boost::mpl::na

      template <>
      struct compose<
        BOOST_PP_REPEAT(
          MPLLIBS_COMPOSE_MAX_ARGUMENT,
          MPLLIBS_COMPOSE_UNUSED_PARAM,
          ~
        )
      >
      {
        template <class T>
        struct apply
        {
          typedef T type;
        };
      };
    
      #ifdef MPLLIBS_COMPOSE_CASE
        #error MPLLIBS_COMPOSE_CASE already defined
      #endif
      #define MPLLIBS_COMPOSE_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class F)> \
        struct compose< \
          BOOST_PP_ENUM_PARAMS(n, F) \
          BOOST_PP_COMMA_IF(n) \
          BOOST_PP_REPEAT( \
            BOOST_PP_SUB(MPLLIBS_COMPOSE_MAX_ARGUMENT, n), \
            MPLLIBS_COMPOSE_UNUSED_PARAM, \
            ~ \
          ) \
        > : compose##n<BOOST_PP_ENUM_PARAMS(n, F)> \
        {};
    
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_COMPOSE_MAX_ARGUMENT,
        MPLLIBS_COMPOSE_CASE,
        ~
      )
    
      #undef MPLLIBS_COMPOSE_CASE
      #undef MPLLIBS_COMPOSE_UNUSED_PARAM
    
      #undef MPLLIBS_REPEAT_CONSTANT
    }
  }
}

#endif

