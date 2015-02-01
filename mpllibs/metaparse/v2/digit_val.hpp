#ifndef MPLLIBS_METAPARSE_V2_DIGIT_VAL_HPP
#define MPLLIBS_METAPARSE_V2_DIGIT_VAL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/digit.hpp>
#include <mpllibs/metaparse/v2/transform.hpp>

#include <mpllibs/metaparse/v2/util/digit_to_int.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      typedef transform<digit, util::digit_to_int<> > digit_val;
    }
  }
}

#endif

