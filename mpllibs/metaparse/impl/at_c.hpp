#ifndef MPLLIBS_METAPARSE_IMPL_AT_C_HPP
#define MPLLIBS_METAPARSE_IMPL_AT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/string_fwd.hpp>

#include <boost/mpl/char.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class S, int N>
      struct at_c;

#ifdef MPLLIBS_VARIADIC_STRING
      template <char C, char... Cs, int N>
      struct at_c<string<C, Cs...>, N> : at_c<string<Cs...>, N - 1> {};

      template <char C, char... Cs>
      struct at_c<string<C, Cs...>, 0> : boost::mpl::char_<C> {};
#else
      #ifdef MPLLIBS_STRING_CASE
        #error MPLLIBS_STRING_CASE is already defined
      #endif
      #define MPLLIBS_STRING_CASE(z, n, unused) \
        template <BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH, int C)> \
        struct \
          at_c< \
            string<BOOST_PP_ENUM_PARAMS(MPLLIBS_STRING_MAX_LENGTH,C)>, \
            n \
          > : \
          boost::mpl::char_<BOOST_PP_CAT(C, n)> \
        {};
    
      BOOST_PP_REPEAT(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_STRING_CASE, ~)

      #undef MPLLIBS_STRING_CASE
#endif
    }
  }
}

#endif

