#ifndef MPLLIBS_METAPARSE_STRING_HPP
#define MPLLIBS_METAPARSE_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/impl/string.hpp>
#include <mpllibs/metaparse/impl/remove_trailing_no_chars.hpp>

#include <boost/preprocessor/repetition/enum.hpp>

/*
 * The MPLLIBS_STRING macro
 */

#if defined MPLLIBS_USE_CONSTEXPR && !defined MPLLIBS_CONFIG_NO_MPLLIBS_STRING

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <int Len, class T>
      constexpr int string_at(const T (&s)[Len], int n)
      {
        return n >= Len - 1 ? MPLLIBS_NO_CHAR : s[n];
      }
    }
  }
}

  #ifdef MPLLIBS_STRING_N
    #error MPLLIBS_STRING_N already defined
  #endif
  #define MPLLIBS_STRING_N(z, n, s) mpllibs::metaparse::impl::string_at((s), n)

  #ifdef MPLLIBS_STRING
    #error MPLLIBS_STRING already defined
  #endif
  #define MPLLIBS_STRING(s) \
    mpllibs::metaparse::impl::remove_trailing_no_chars< \
      mpllibs::metaparse::string< \
        BOOST_PP_ENUM(MPLLIBS_STRING_MAX_LENGTH, MPLLIBS_STRING_N, s) \
      > \
    >::type

#else

  // Include it only when it is needed
  #include <boost/static_assert.hpp>

  #ifdef MPLLIBS_STRING
    #error MPLLIBS_STRING already defined
  #endif
  #define MPLLIBS_STRING(s) \
    BOOST_STATIC_ASSERT_MSG(false, "MPLLIBS_STRING is not supported")

  #define MPLLIBS_CONFIG_NO_MPLLIBS_STRING

#endif

#endif

