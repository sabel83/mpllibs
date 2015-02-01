#ifndef MPLLIBS_METAPARSE_V2_LETTER_HPP
#define MPLLIBS_METAPARSE_V2_LETTER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/error/letter_expected.hpp>
#include <mpllibs/metaparse/v2/accept_when.hpp>
#include <mpllibs/metaparse/v2/one_char.hpp>

#include <mpllibs/metaparse/v2/util/is_letter.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      typedef
        accept_when<one_char, util::is_letter<>, error::letter_expected>
        letter;
    }
  }
}

#endif

