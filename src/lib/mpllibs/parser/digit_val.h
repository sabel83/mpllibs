#ifndef MPLLIBS_PARSER_DIGIT_VAL_H
#define MPLLIBS_PARSER_DIGIT_VAL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/transform.h>

#include <mpllibs/util/digit_to_int.h>

namespace mpllibs
{
  namespace parser
  {
    typedef
      mpllibs::parser::transform<
        mpllibs::parser::digit,
        mpllibs::util::digit_to_int
      >
      digit_val;
  }
}

#endif

