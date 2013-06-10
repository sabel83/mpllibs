#ifndef MPLLIBS_METAPARSE_IMPL_PUSH_FRONT_C_HPP
#define MPLLIBS_METAPARSE_IMPL_PUSH_FRONT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/string_fwd.hpp>

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class S, char C>
      struct push_front_c;

#ifdef MPLLIBS_VARIADIC_STRING
      template <char... Cs, char C>
      struct push_front_c<string<Cs...>, C> : string<C, Cs...> {};
#else
      template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C), char Ch>
      struct push_front_c<
        string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, C)>,
        Ch
      > :
        string<
          Ch,
          BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(MPLLIBS_STRING_MAX_LENGTH), C)
        >
      {};
#endif
    }
  }
}

#endif

