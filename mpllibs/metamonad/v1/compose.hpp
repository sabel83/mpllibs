#ifndef MPLLIBS_METAMONAD_V1_COMPOSE_HPP
#define MPLLIBS_METAMONAD_V1_COMPOSE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/limit_compose_size.hpp>
#include <mpllibs/metamonad/v1/impl/compose.hpp>

#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_COMPOSE_SIZE,
          class F,
          boost::mpl::na
        )
      >
      struct compose;
      
      template <>
      struct compose<
        BOOST_PP_ENUM(
          MPLLIBS_LIMIT_COMPOSE_SIZE,
          boost::mpl::na BOOST_PP_TUPLE_EAT(3),
          ~
        )
      >
      {
        typedef compose type;

        template <class T>
        struct apply
        {
          typedef T type;
        };
      };
      
      #ifdef MPLLIBS_COMPOSE_CASE
      #  error MPLLIBS_COMPOSE_CASE already defined
      #endif
      #define MPLLIBS_COMPOSE_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(n, class F)> \
        struct compose< \
          BOOST_PP_ENUM_PARAMS(n, F) \
          BOOST_PP_COMMA_IF(n) \
          BOOST_PP_ENUM( \
            BOOST_PP_SUB(MPLLIBS_LIMIT_COMPOSE_SIZE, n), \
            boost::mpl::na BOOST_PP_TUPLE_EAT(3), \
            ~ \
          ) \
        > : impl::BOOST_PP_CAT(compose, n)<BOOST_PP_ENUM_PARAMS(n, F)> \
        { \
          typedef compose type; \
        };
      
      BOOST_PP_REPEAT_FROM_TO(
        1,
        MPLLIBS_LIMIT_COMPOSE_SIZE,
        MPLLIBS_COMPOSE_CASE,
        ~
      )
      
      #undef MPLLIBS_COMPOSE_CASE
    }
  }
}

#endif

