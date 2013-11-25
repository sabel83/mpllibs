#ifndef MPLLIBS_METAPARSE_V1_UTIL_INT_TO_DIGIT_HPP
#define MPLLIBS_METAPARSE_V1_UTIL_INT_TO_DIGIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/util/int_to_digit_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace util
      {
        template <class N>
        struct int_to_digit : int_to_digit_c<N::type::value> {};
      }
    }
  }
}

#endif

