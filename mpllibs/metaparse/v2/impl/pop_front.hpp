#ifndef MPLLIBS_METAPARSE_V2_IMPL_POP_FRONT_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_POP_FRONT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/v2/fwd/string.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <class S>
        struct pop_front;

#ifdef MPLLIBS_VARIADIC_STRING
        template <char C, char... Cs>
        struct pop_front<string<C, Cs...>> : string<Cs...> {};
#else
        #ifdef MPLLIBS_POP_FRONT
        #  error MPLLIBS_POP_FRONT already defined
        #endif
        #define MPLLIBS_POP_FRONT(z, n, unused) \
          BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) BOOST_PP_CAT(C, n)

        template <BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_STRING_SIZE, int C)>
        struct
          pop_front<
            string<BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_STRING_SIZE, C)>
          > :
          string<
            BOOST_PP_REPEAT_FROM_TO(
              1,
              MPLLIBS_LIMIT_STRING_SIZE,
              MPLLIBS_POP_FRONT,
              ~
            ),
            MPLLIBS_NO_CHAR
          >
        {};

        #undef MPLLIBS_POP_FRONT
#endif
      }
    }
  }
}

#endif

