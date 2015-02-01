#ifndef MPLLIBS_METAPARSE_V2_IMPL_ASSERT_STRING_LENGTH_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_ASSERT_STRING_LENGTH_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/static_assert.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <int Len, class S>
        struct assert_string_length : S
        {
          BOOST_STATIC_ASSERT((Len <= MPLLIBS_LIMIT_STRING_SIZE));
        };
      }
    }
  }
}

#endif


