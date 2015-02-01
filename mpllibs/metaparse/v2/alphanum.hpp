#ifndef MPLLIBS_METAPARSE_V2_ALPHANUM_HPP
#define MPLLIBS_METAPARSE_V2_ALPHANUM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/one_of.hpp>
#include <mpllibs/metaparse/v2/digit.hpp>
#include <mpllibs/metaparse/v2/letter.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      typedef one_of<letter, digit> alphanum;
    }
  }
}

#endif

