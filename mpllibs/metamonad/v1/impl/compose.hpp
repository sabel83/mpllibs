#ifndef MPLLIBS_METAMONAD_V1_IMPL_COMPOSE_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_COMPOSE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/limit_compose_size.hpp>
#include <mpllibs/metamonad/limit_compose_arg_size.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#include <boost/mpl/apply.hpp>

#if MPLLIBS_LIMIT_COMPOSE_ARG_SIZE >= BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#  error MPLLIBS_LIMIT_COMPOSE_ARG_SIZE >= BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#endif
      
namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        #ifdef MPLLIBS_COMPOSE
        #  error MPLLIBS_COMPOSE already defined
        #endif
        #define MPLLIBS_COMPOSE(z, n, unused) \
          template <BOOST_PP_ENUM_PARAMS(n, class F)> \
          struct BOOST_PP_CAT(compose, n) \
          { \
            template < \
              BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT( \
                MPLLIBS_LIMIT_COMPOSE_ARG_SIZE, \
                class A, \
                boost::mpl::na \
              ) \
            > \
            struct apply \
            { \
              typedef \
                BOOST_PP_ENUM_PARAMS(n, typename boost::mpl::apply<F) \
                  BOOST_PP_COMMA_IF(n) \
                  BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_COMPOSE_ARG_SIZE, A) \
                BOOST_PP_REPEAT(n, >::type BOOST_PP_TUPLE_EAT(3), ~) \
                type; \
            }; \
          };
        
        BOOST_PP_REPEAT_FROM_TO(
          1,
          MPLLIBS_LIMIT_COMPOSE_SIZE,
          MPLLIBS_COMPOSE,
          ~
        )
        
        #undef MPLLIBS_COMPOSE
      }
    }
  }
}

#endif

