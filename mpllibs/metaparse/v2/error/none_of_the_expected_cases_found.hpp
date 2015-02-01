#ifndef MPLLIBS_METAPARSE_V2_ERROR_NONE_OF_THE_EXPECTED_CASES_FOUND_HPP
#define MPLLIBS_METAPARSE_V2_ERROR_NONE_OF_THE_EXPECTED_CASES_FOUND_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
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
        MPLLIBS_V2_DEFINE_ERROR(
          none_of_the_expected_cases_found,
          "None of the expected cases found"
        );
      }
    }
  }
}

#endif

