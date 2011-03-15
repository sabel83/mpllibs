#ifndef MPLLIBS_PARSER_LETTER_H
#define MPLLIBS_PARSER_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.h>
#include <mpllibs/metaparse/one_char.h>

#include <mpllibs/metaparse/util/is_letter.h>
#include <mpllibs/metaparse/util/define_data.h>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_METAPARSE_DEFINE_DATA(letter_expected);
    }
    
    typedef
      mpllibs::metaparse::accept_when<
        mpllibs::metaparse::one_char,
        mpllibs::metaparse::util::is_letter,
        mpllibs::metaparse::errors::letter_expected
      >
      letter;
  }
}

#endif

