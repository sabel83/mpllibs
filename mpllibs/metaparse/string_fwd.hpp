#ifndef MPLLIBS_METAPARSE_STRING_FWD_HPP
#define MPLLIBS_METAPARSE_STRING_FWD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#include <cstdio>

#ifndef MPLLIBS_STRING_MAX_LENGTH
  #define MPLLIBS_STRING_MAX_LENGTH 32
#endif

#ifdef MPLLIBS_NO_CHAR
  #error MPLLIBS_NO_CHAR already defined
#endif
#define MPLLIBS_NO_CHAR EOF

namespace mpllibs
{
  namespace metaparse
  {
#ifdef MPLLIBS_VARIADIC_STRING
    template <char... Cs>
    struct string;
#else
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_STRING_MAX_LENGTH,
        int C,
        MPLLIBS_NO_CHAR
      )
    >
    struct string;
#endif
  }
}

#endif

