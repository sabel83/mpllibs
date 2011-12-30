#ifndef MPLLIBS_METAPARSE_ONE_CHAR_EXCEPT_C_HPP
#define MPLLIBS_METAPARSE_ONE_CHAR_EXCEPT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_char_except.hpp>

#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT,
        int C,
        1024
      )
    >
    struct one_char_except_c;

    #ifdef MPLLIBS_METAPARSE_UNUSED
      #error MPLLIBS_METAPARSE_UNUSED already defined
    #endif
    #define MPLLIBS_METAPARSE_UNUSED(z, n, unused) \
      BOOST_PP_COMMA_IF(n) 1024

    #ifdef MPLLIBS_METAPARSE_WRAP
      #error MPLLIBS_METAPARSE_WRAP already defined
    #endif
    #define MPLLIBS_METAPARSE_WRAP(z, n, unused) \
      BOOST_PP_COMMA_IF(n) boost::mpl::char_<BOOST_PP_CAT(C, n)>

    #ifdef MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE
      #error MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE already defined
    #endif
    #define MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE(z, n, unused) \
      template <BOOST_PP_ENUM_PARAMS(n, int C)> \
      struct one_char_except_c< \
        BOOST_PP_ENUM_PARAMS(n, C) \
        BOOST_PP_REPEAT_FROM_TO( \
          n, \
          BOOST_PP_DEC(MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT), \
          MPLLIBS_METAPARSE_UNUSED, \
          ~ \
        ) \
      > :\
        accept_when< \
          one_char, \
          impl::is_any##n<BOOST_PP_REPEAT(n, MPLLIBS_METAPARSE_WRAP, ~)>, \
          errors::unexpected_character \
        > \
      {};

    BOOST_PP_REPEAT(
      MPLLIBS_ONE_CHAR_EXCEPT_MAX_ARGUMENT,
      MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE,
      ~
    )

    #undef MPLLBIS_METAPARSE_ONE_CHAR_EXCEPT_CASE
    #undef MPLLIBS_METAPARSE_UNUSED
    #undef MPLLIBS_METAPARSE_WRAP
  }
}

#endif

