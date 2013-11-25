#ifndef MPLLIBS_METAPARSE_V1_DIGIT_HPP
#define MPLLIBS_METAPARSE_V1_DIGIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/error/digit_expected.hpp>
#include <mpllibs/metaparse/v1/accept_when.hpp>
#include <mpllibs/metaparse/v1/one_char.hpp>

#include <mpllibs/metaparse/v1/util/is_digit.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      typedef
        accept_when<one_char, util::is_digit<>, error::digit_expected>
        digit;
    }
  }
}

#endif

