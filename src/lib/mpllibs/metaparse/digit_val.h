#ifndef MPLLIBS_PARSER_DIGIT_VAL_H
#define MPLLIBS_PARSER_DIGIT_VAL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/transform.h>

#include <mpllibs/metaparse/util/digit_to_int.h>

namespace mpllibs
{
  namespace metaparse
  {
    typedef
      mpllibs::metaparse::transform<
        mpllibs::metaparse::digit,
        mpllibs::metaparse::util::digit_to_int
      >
      digit_val;
  }
}

#endif

