#ifndef MPLLIBS_METAPARSE_V2_ERROR_LITERAL_EXPECTED_HPP
#define MPLLIBS_METAPARSE_V2_ERROR_LITERAL_EXPECTED_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace error
      {
        template <char C>
        struct literal_expected
        {
          typedef literal_expected type;

          static std::string get_value()
          {
            return std::string("Expected: ") + C;
          }
        };
      }
    }
  }
}

#endif


