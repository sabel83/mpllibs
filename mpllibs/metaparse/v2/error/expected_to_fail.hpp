#ifndef MPLLIBS_METAPARSE_V2_ERROR_EXPECTED_TO_FAIL_HPP
#define MPLLIBS_METAPARSE_V2_ERROR_EXPECTED_TO_FAIL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/define_error.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace error
      {
        MPLLIBS_V2_DEFINE_ERROR(expected_to_fail, "Parser expected to fail");
      }
    }
  }
}

#endif


