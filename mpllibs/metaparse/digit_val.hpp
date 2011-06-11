#ifndef MPLLIBS_METAPARSE_DIGIT_VAL_HPP
#define MPLLIBS_METAPARSE_DIGIT_VAL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/transform.hpp>

#include <mpllibs/metaparse/util/digit_to_int.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    typedef transform<digit, mpllibs::metaparse::util::digit_to_int> digit_val;
  }
}

#endif

