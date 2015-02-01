#ifndef MPLLIBS_METAPARSE_V2_FWD_STRING_HPP
#define MPLLIBS_METAPARSE_V2_FWD_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/limit_string_size.hpp>
#include <mpllibs/metaparse/v2/impl/no_char.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
#ifdef MPLLIBS_VARIADIC_STRING
      template <char... Cs>
      struct string;
#else
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_STRING_SIZE,
          int C,
          MPLLIBS_NO_CHAR
        )
      >
      struct string;
#endif
    }
  }
}

#endif

