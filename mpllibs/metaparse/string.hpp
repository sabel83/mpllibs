#ifndef MPLLIBS_METAPARSE_STRING_HPP
#define MPLLIBS_METAPARSE_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/string.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/char.hpp>

#ifndef MPLLIBS_METAPARSE_STRING_MAX_LENGTH
  #define MPLLIBS_METAPARSE_STRING_MAX_LENGTH 32
#endif

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class S, char C, bool EndOfString>
      struct append_string : boost::mpl::push_back<S, boost::mpl::char_<C>> {};
      
      template <class S, char C>
      struct append_string<S, C, true> : S {};

      constexpr char string_at(const char s[], int len, int n)
      {
        return n >= len ? 0 : s[n];
      }
    }
  }
}

#ifdef MPLLIBS_METAPARSE_STRING_PRE
  #error MPLLIBS_METAPARSE_STRING_PRE already defined
#endif
#define MPLLIBS_METAPARSE_STRING_PRE(z, n, unused) \
  mpllibs::metaparse::impl::append_string< \

#ifdef MPLLIBS_METAPARSE_STRING_POST
  #error MPLLIBS_METAPARSE_STRING_POST already defined
#endif
#define MPLLIBS_METAPARSE_STRING_POST(z, n, str) \
    , \
    mpllibs::metaparse::impl::string_at(str, sizeof(str), n), \
    (n >= sizeof(str) - 1) \
  >::type

#ifdef MPLLIBS_METAPARSE_STRING
  #error MPLLIBS_METAPARSE_STRING already defined
#endif
#define MPLLIBS_METAPARSE_STRING(s) \
  BOOST_PP_REPEAT( \
    MPLLIBS_METAPARSE_STRING_MAX_LENGTH, \
    MPLLIBS_METAPARSE_STRING_PRE, \
    ~\
  ) \
    boost::mpl::string<> \
  BOOST_PP_REPEAT( \
    MPLLIBS_METAPARSE_STRING_MAX_LENGTH, \
    MPLLIBS_METAPARSE_STRING_POST, \
    s \
  )

#ifdef _S
  #error _S already defined
#endif
#define _S MPLLIBS_METAPARSE_STRING

#endif

