#ifndef MPLLIBS_METAPARSE_CONFIG_HPP
#define MPLLIBS_METAPARSE_CONFIG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>

/*
 * C++11 features
 */

#if \
  !defined BOOST_NO_CXX11_VARIADIC_TEMPLATES \
  && !defined BOOST_NO_VARIADIC_TEMPLATES \
  \
  && !defined MPLLIBS_NO_VARIADIC_TEMPLATES \
  && !defined MPLLIBS_USE_VARIADIC_TEMPLATES

  #define MPLLIBS_USE_VARIADIC_TEMPLATES

#endif

#if \
  !defined BOOST_NO_CONSTEXPR \
  && !defined BOOST_NO_CXX11_CONSTEXPR \
  \
  && !defined MPLLIBS_NO_CONSTEXPR \
  && !defined MPLLIBS_USE_CONSTEXPR

  #define MPLLIBS_USE_CONSTEXPR

#endif

#ifdef MPLLIBS_USE_CONSTEXPR
#  define MPLLIBS_CONSTEXPR constexpr
#else
#  define MPLLIBS_CONSTEXPR
#endif

/*
 * Compiler workarounds
 */

#if defined __GNUC__ && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 7))
#  define MPLLIBS_NO_CONSTEXPR_C_STR
#endif

/*
 * Metaparse config
 */

#if defined MPLLIBS_USE_VARIADIC_TEMPLATES && !defined MPLLIBS_VARIADIC_STRING
#  define MPLLIBS_VARIADIC_STRING
#endif

#endif

