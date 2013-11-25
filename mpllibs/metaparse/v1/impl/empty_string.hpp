#ifndef MPLLIBS_METAPARSE_V1_IMPL_EMPTY_STRING_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_EMPTY_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <class Ignore = int>
        struct empty_string
        {
          typedef empty_string type;

          #if defined MPLLIBS_USE_CONSTEXPR && !defined MPLLIBS_NO_CONSTEXPR_C_STR
            static constexpr const char value[1] = {0};
          #else
            static const char value[1];
          #endif
        };

        #if defined MPLLIBS_USE_CONSTEXPR && !defined MPLLIBS_NO_CONSTEXPR_C_STR
          template <class Ignore>
          constexpr const char empty_string<Ignore>::value[1];
        #else
          template <class Ignore>
          const char empty_string<Ignore>::value[1] = {0};
        #endif
      }
    }
  }
}

#endif

