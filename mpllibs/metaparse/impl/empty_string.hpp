#ifndef MPLLIBS_METAPARSE_IMPL_EMPTY_STRING_HPP
#define MPLLIBS_METAPARSE_IMPL_EMPTY_STRING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class Ignore = int>
      struct empty_string
      {
        typedef empty_string type;
        static MPLLIBS_CONSTEXPR const char value[1]
        #ifdef MPLLIBS_USE_CONSTEXPR
          = {0}
        #endif
          ;
      };

      template <class Ignore>
      MPLLIBS_CONSTEXPR const char empty_string<Ignore>::value[1]
      #ifndef MPLLIBS_USE_CONSTEXPR
        = {0}
      #endif
        ;
      ;
    }
  }
}

#endif

